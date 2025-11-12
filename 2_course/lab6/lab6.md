# Отчет по лабораторной работе
## Тема: Работа с API, декораторы и логирование

---

### Задача: Получение курсов валют с API ЦБ РФ

#### Постановка задачи

Разработать функцию `get_currencies(currency_codes, url)`, которая обращается к API Центробанка РФ и возвращает словарь курсов валют для указанных валютных кодов. Функция должна обрабатывать ошибки и включать систему логирования.

#### Математическая модель

```
get_currencies(C, U) = {
    {c: rate(c) для каждого c ∈ C}, если запрос успешен
    None, если произошла ошибка
}
```

где:
- C - множество кодов валют
- U - URL API
- rate(c) - курс валюты c

---

## Итерация 1: Базовая реализация с логированием в stdout

### Код программы (`iteration1.py`)

```python
import requests
import sys

def get_currencies(currency_codes, url="https://www.cbr-xml-daily.ru/daily_json.js"):
    """
    Получает курсы валют из API ЦБ РФ
    
    Args:
        currency_codes (list): Список кодов валют (например, ['USD', 'EUR'])
        url (str): URL API ЦБ РФ
    
    Returns:
        dict: Словарь с курсами валют или None в случае ошибки
    """
    try:
        response = requests.get(url)
        response.raise_for_status()  # Проверка на HTTP ошибки
        
        data = response.json()
        
        # Проверка наличия курсов валют в ответе
        if 'Valute' not in data:
            print(f"Ошибка: в ответе API отсутствуют курсы валют", file=sys.stdout)
            return None
        
        valutes = data['Valute']
        result = {}
        
        # Формирование результата только для запрошенных валют
        for code in currency_codes:
            if code not in valutes:
                print(f"Ошибка: валюта {code} не найдена в ответе API", file=sys.stdout)
                return None
            
            # Получаем курс валюты
            currency_data = valutes[code]
            result[code] = currency_data['Value']
        
        return result
        
    except requests.exceptions.RequestException as e:
        print(f"Ошибка запроса к API: {e}", file=sys.stdout)
        return None
    except KeyError as e:
        print(f"Ошибка структуры данных: отсутствует ключ {e}", file=sys.stdout)
        return None
    except Exception as e:
        print(f"Неожиданная ошибка: {e}", file=sys.stdout)
        return None
```

#### Список идентификаторов

| Имя переменной    | Тип данных | Описание                              |
|-------------------|------------|---------------------------------------|
| `currency_codes`  | list       | Список кодов валют для получения      |
| `url`             | str        | URL API ЦБ РФ                         |
| `response`        | Response   | Ответ от сервера                      |
| `data`            | dict       | JSON данные из ответа                 |
| `valutes`         | dict       | Словарь с курсами валют               |
| `result`          | dict       | Результирующий словарь курсов         |

#### Обрабатываемые исключения

1. **RequestException** - ошибки сетевого запроса
2. **KeyError** - отсутствие ожидаемых ключей в JSON
3. **Exception** - все прочие неожиданные ошибки

#### Результат работы программы

```python
# Успешный запрос
currencies = get_currencies(['USD', 'EUR'])
# Результат: {'USD': 75.5, 'EUR': 85.2}

# Запрос с несуществующей валютой  
currencies = get_currencies(['USD', 'XYZ'])
# Результат: None
# В stdout: "Ошибка: валюта XYZ не найдена в ответе API"
```

---

## Итерация 2: Логирование через декоратор

### Код программы (`iteration2.py`)

```python
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
```

#### Архитектурные улучшения

1. **Разделение ответственности** - логика обработки ошибок вынесена в декоратор
2. **Чистота функции** - основная функция содержит только бизнес-логику
3. **Повторное использование** - декоратор можно применять к другим функциям

#### Принцип работы декоратора

```
log_errors(func)(args) = {
    func(args), если выполнение успешно
    None + запись в лог, если произошла ошибка
}
```

---

## Итерация 3: Профессиональное логирование с logging

### Код программы (`iteration3.py`)

```python
import requests
import logging

# Настройка логирования
logging.basicConfig(
    level=logging.INFO,
    format='%(asctime)s - %(levelname)s - %(message)s',
    handlers=[
        logging.StreamHandler(),  # Вывод в консоль
        logging.FileHandler('currency_errors.log')  # Запись в файл
    ]
)

logger = logging.getLogger(__name__)

def log_errors(func):
    """
    Декоратор для логирования ошибок с использованием модуля logging
    """
    def wrapper(currency_codes, url="https://www.cbr-xml-daily.ru/daily_json.js"):
        try:
            logger.info(f"Запрос курсов валют: {currency_codes}")
            result = func(currency_codes, url)
            if result:
                logger.info(f"Успешно получены курсы для {list(result.keys())}")
            return result
        except requests.exceptions.RequestException as e:
            logger.error(f"Ошибка запроса к API {url}: {e}")
            return None
        except KeyError as e:
            logger.error(f"Ошибка структуры данных: отсутствует ключ {e}")
            return None
        except Exception as e:
            logger.exception(f"Неожиданная ошибка при получении курсов валют: {e}")
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
```

#### Преимущества использования logging

1. **Уровни логирования** - INFO, ERROR, DEBUG и др.
2. **Форматирование** - стандартизированный формат записей
3. **Множественные обработчики** - вывод в консоль и файл одновременно
4. **Трассировка** - logger.exception включает stack trace

#### Пример лога

```
2024-01-15 10:30:45 - INFO - Запрос курсов валют: ['USD', 'EUR']
2024-01-15 10:30:46 - INFO - Успешно получены курсы для ['USD', 'EUR']
2024-01-15 10:31:20 - ERROR - Ошибка структуры данных: отсутствует ключ 'Валюта XYZ не найдена'
```

---

## Тестирование

### Код тестов (`test_currencies.py`)

```python
import unittest
from unittest.mock import patch, Mock
import sys
from io import StringIO

class TestCurrencyFunctions(unittest.TestCase):
    
    def setUp(self):
        self.valid_currency_codes = ['USD', 'EUR']
        self.invalid_currency_codes = ['USD', 'XYZ']
        self.mock_valid_response = {
            'Valute': {
                'USD': {'Value': 75.5},
                'EUR': {'Value': 85.2}
            }
        }
    
    def test_v1_valid_currencies(self):
        """Тест корректного запроса для итерации 1"""
        with patch('iteration1.requests.get') as mock_get:
            mock_get.return_value.json.return_value = self.mock_valid_response
            mock_get.return_value.raise_for_status = Mock()
            
            result = get_currencies_v1(self.valid_currency_codes)
            
            self.assertIsNotNone(result)
            self.assertEqual(set(result.keys()), set(self.valid_currency_codes))
            self.assertIsInstance(result['USD'], float)
            self.assertIsInstance(result['EUR'], float)
    
    def test_v1_invalid_currency(self):
        """Тест с несуществующей валютой для итерации 1"""
        with patch('iteration1.requests.get') as mock_get:
            mock_get.return_value.json.return_value = {
                'Valute': {'USD': {'Value': 75.5}}
            }
            mock_get.return_value.raise_for_status = Mock()
            
            captured_output = StringIO()
            sys.stdout = captured_output
            
            result = get_currencies_v1(self.invalid_currency_codes)
            
            sys.stdout = sys.__stdout__
            
            self.assertIsNone(result)
            self.assertIn("XYZ", captured_output.getvalue())
```

#### Сценарии тестирования

1. **Успешный запрос** - проверка корректности данных
2. **Несуществующая валюта** - проверка обработки ошибки
3. **Ошибка сети** - проверка устойчивости к сетевым проблемам
4. **Неверная структура JSON** - проверка обработки некорректных данных

---

## Выводы

1. **Эволюция архитектуры** - от монолитной функции к разделенной системе с декораторами
2. **Улучшение сопровождаемости** - каждая итерация делает код более поддерживаемым
3. **Профессиональное логирование** - переход от простого вывода к продвинутой системе логирования
4. **Обработка ошибок** - все реализации надежно обрабатывают исключительные ситуации
5. **Тестируемость** - код легко покрывается модульными тестами

### Сравнение итераций

| Критерий | Итерация 1 | Итерация 2 | Итерация 3 |
|----------|------------|------------|------------|
| Разделение ответственности | Низкое | Высокое | Высокое |
| Повторное использование кода | Низкое | Среднее | Высокое |
| Качество логирования | Базовое | Базовое | Профессиональное |
| Гибкость настройки | Низкая | Средняя | Высокая |

**Рекомендация**: Для production-систем рекомендуется использовать подход из Итерации 3, как наиболее надежный и сопровождаемый.

---

### Информация о студенте:

*Аглиуллин Амир, 1 курс, ИВТ-1(2).*