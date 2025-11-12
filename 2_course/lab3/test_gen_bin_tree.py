import unittest
from lab3 import gen_bin_tree

class TestMyBinTree(unittest.TestCase):
    
    def test_bin_tree_values(self):
        """Тест проверки значений узлов дерева"""
        result = gen_bin_tree(height=5, root=1)
        
        # Все ожидаемые значения в порядке обхода дерева
        expected_values = [
            # Корень
            1,
            # Уровень 2
            2, 4,
            # Уровень 3  
            4, 5, 8, 7,
            # Уровень 4
            8, 7, 10, 8, 16, 11, 14, 10
        ]
        
        # Функция для сбора всех значений из дерева
        def collect_values(node):
            if not node:
                return []
            return [node["value"]] + collect_values(node.get("left")) + collect_values(node.get("right"))
        
        actual_values = collect_values(result)
        self.assertEqual(actual_values, expected_values)

if __name__ == '__main__':
    unittest.main()