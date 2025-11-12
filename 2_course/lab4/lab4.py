from collections import deque

def gen_bin_tree(height=5, root=1, left_child_func=None, right_child_func=None):
    """
    Генерирует бинарное дерево в виде словаря.
    
    Args:
        height (int): Высота дерева
        root: Значение корневого узла
        left_child_func (callable): Функция для вычисления левого потомка
        right_child_func (callable): Функция для вычисления правого потомка
    
    Returns:
        dict: Представление бинарного дерева
    """
    # 1. Дерево высотой 0 содержит только корень
    if height == 0:
        return {root: {'left': None, 'right': None}}
    
    # Базовый случай: если высота дерева меньше 0, возвращаем пустое дерево
    if height < 0:
        return {}
    
    # 2. Устанавливаем функции по умолчанию если не переданы
    if left_child_func is None:
        left_child_func = lambda x: x * 2
    if right_child_func is None:
        right_child_func = lambda x: x + 3
    
    # Инициализация словаря для хранения структуры дерева
    tree = {}
    # 3. Используем deque для реализации очереди
    queue = deque()
    queue.append((root, 1))  # Добавляем корневой узел с уровнем 1

    # Основной цикл: обрабатываем узлы пока очередь не пуста
    while queue:
        # Извлекаем первый элемент из очереди (FIFO)
        value, level_height = queue.popleft()

        # Создаем запись для текущего узла в словаре дерева
        tree[value] = {}

        # Проверяем, не достигли ли максимальной высоты дерева
        if level_height < height:
            # Вычисляем значения для левого и правого потомков используя переданные функции
            left_leaf = left_child_func(value)
            right_leaf = right_child_func(value)

            # Добавляем потомков в структуру текущего узла
            tree[value]['left'] = left_leaf
            tree[value]['right'] = right_leaf

            # Добавляем потомков в очередь для дальнейшей обработки
            queue.append((left_leaf, level_height + 1))
            queue.append((right_leaf, level_height + 1))
        else:
            # Если достигли максимальной высоты - устанавливаем потомков как None (листья)
            tree[value]['left'] = None
            tree[value]['right'] = None
            
    # Возвращаем готовое бинарное дерево в виде словаря
    return tree