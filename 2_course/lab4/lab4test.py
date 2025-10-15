import unittest
from lab4 import gen_bin_tree

class TestGenBinTree(unittest.TestCase):
    
    def test_zero_height(self):
        """Тест для высоты 0 - должно вернуться пустое дерево"""
        result = gen_bin_tree(height=0)
        self.assertEqual(result, {})
    
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
        expected = {
            1: {'left': 2, 'right': 4},
            2: {'left': None, 'right': None},
            4: {'left': None, 'right': None}
        }
        self.assertEqual(result, expected)
    
    def test_height_three_custom_root(self):
        """Тест для высоты 3 с пользовательским корнем"""
        result = gen_bin_tree(height=3, root=5)
        # Проверяем структуру дерева
        self.assertIn(5, result)
        self.assertIn(10, result)  # 5*2
        self.assertIn(8, result)   # 5+3
        
        # Проверяем потомков корня
        self.assertEqual(result[5]['left'], 10)
        self.assertEqual(result[5]['right'], 8)
        
        # Проверяем потомков узла 10
        self.assertEqual(result[10]['left'], 20)  # 10*2
        self.assertEqual(result[10]['right'], 13) # 10+3
        
        # Проверяем потомков узла 8
        self.assertEqual(result[8]['left'], 16)  # 8*2
        self.assertEqual(result[8]['right'], 11) # 8+3
        
        # Проверяем что листья имеют None-потомков
        self.assertEqual(result[20]['left'], None)
        self.assertEqual(result[20]['right'], None)
        self.assertEqual(result[13]['left'], None)
        self.assertEqual(result[13]['right'], None)
        self.assertEqual(result[16]['left'], None)
        self.assertEqual(result[16]['right'], None)
        self.assertEqual(result[11]['left'], None)
        self.assertEqual(result[11]['right'], None)
    
if __name__ == '__main__':
    # Запуск тестов
    unittest.main()