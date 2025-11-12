import unittest
from lab4 import gen_bin_tree

class TestGenBinTree(unittest.TestCase):
    
    def test_zero_height(self):
        """Тест для высоты 0 - должно вернуться дерево только с корнем"""
        result = gen_bin_tree(height=0, root=10)
        expected = {
            10: {'left': None, 'right': None}
        }
        self.assertEqual(result, expected)
    
    def test_negative_height(self):
        """Тест для отрицательной высоты - должно вернуться пустое дерево"""
        result = gen_bin_tree(height=-1)
        self.assertEqual(result, {})
    
    def test_height_one(self):
        """Тест для высоты 1 - только корневой узел с пустыми потомками"""
        result = gen_bin_tree(height=1, root=10)
        expected = {
            10: {'left': None, 'right': None}
        }
        self.assertEqual(result, expected)
    
    def test_height_two_default_root(self):
        """Тест для высоты 2 с корнем по умолчанию"""
        result = gen_bin_tree(height=2, root=1)
        # 4. Сравниваем с составленным вручную деревом
        expected = {
            1: {'left': 2, 'right': 4},
            2: {'left': None, 'right': None},
            4: {'left': None, 'right': None}
        }
        self.assertEqual(result, expected)
    
    def test_height_three_custom_root(self):
        """Тест для высоты 3 с пользовательским корнем"""
        result = gen_bin_tree(height=3, root=5)
        # 4. Сравниваем с составленным вручную деревом
        expected = {
            5: {'left': 10, 'right': 8},
            10: {'left': 20, 'right': 13},
            8: {'left': 16, 'right': 11},
            20: {'left': None, 'right': None},
            13: {'left': None, 'right': None},
            16: {'left': None, 'right': None},
            11: {'left': None, 'right': None}
        }
        self.assertEqual(result, expected)
    
    def test_custom_child_functions(self):
        """Тест с пользовательскими функциями для вычисления потомков"""
        # 2. Передаем алгоритмы вычисления потомков
        left_func = lambda x: x + 1
        right_func = lambda x: x + 2
        
        result = gen_bin_tree(height=2, root=1, 
                             left_child_func=left_func, 
                             right_child_func=right_func)
        
        # 4. Сравниваем с составленным вручную деревом
        expected = {
            1: {'left': 2, 'right': 3},
            2: {'left': None, 'right': None},
            3: {'left': None, 'right': None}
        }
        self.assertEqual(result, expected)

if __name__ == '__main__':
    unittest.main()