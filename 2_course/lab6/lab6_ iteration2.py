import requests
import sys

def log_errors(func):
    """
    Декоратор для логирования ошибок в stdout
    """
    def wrapper(currency_codes, url="https://www.cbr-xml-daily.ru/daily_json.js"):
        try:
            return func(currency_codes, url)
        except requests.exceptions.RequestException as e:
            print(f"Ошибка запроса к API: {e}", file=sys.stdout)
            return None
        except KeyError as e:
            print(f"Ошибка структуры данных: отсутствует ключ {e}", file=sys.stdout)
            return None
        except Exception as e:
            print(f"Неожиданная ошибка: {e}", file=sys.stdout)
            return None
    return wrapper

@log_errors
def get_currencies(currency_codes, url="https://www.cbr-xml-daily.ru/daily_json.js"):
    """
    Получает курсы валют из API ЦБ РФ
    
    Args:
        currency_codes (list): Список кодов валют (например, ['USD', 'EUR'])
        url (str): URL API ЦБ РФ
    
    Returns:
        dict: Словарь с курсами валют или None в случае ошибки
    """
    response = requests.get(url)
    response.raise_for_status()  # Проверка на HTTP ошибки
    
    data = response.json()
    
    # Проверка наличия курсов валют в ответе
    if 'Valute' not in data:
        raise KeyError('Valute')
    
    valutes = data['Valute']
    result = {}
    
    # Формирование результата только для запрошенных валют
    for code in currency_codes:
        if code not in valutes:
            raise KeyError(f"Валюта {code} не найдена")
        
        # Получаем курс валюты
        currency_data = valutes[code]
        result[code] = currency_data['Value']
    
    return result

# Пример использования
if __name__ == "__main__":
    # Тест корректного запроса
    currencies = get_currencies(['USD', 'EUR'])
    print("Курсы валют:", currencies)
    
    # Тест с несуществующей валютой
    currencies = get_currencies(['USD', 'XYZ'])
    print("Результат с несуществующей валютой:", currencies)