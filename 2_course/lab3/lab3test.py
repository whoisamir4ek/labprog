import unittest
from lab3 import gen_bin_tree

class TestMyBinTree(unittest.TestCase):
    
    def test_my_parameters(self):
        """Тест для моих параметров: root=1, height=5"""
        result = gen_bin_tree(height=5, root=1)
        
        # Проверяем корень
        self.assertEqual(result["value"], 1)
        
        # Проверяем второй уровень
        self.assertEqual(result["left"]["value"], 2)   # 1 * 2
        self.assertEqual(result["right"]["value"], 4)  # 1 + 3
        
        # Проверяем третий уровень
        self.assertEqual(result["left"]["left"]["value"], 4)   # 2 * 2
        self.assertEqual(result["left"]["right"]["value"], 5)  # 2 + 3
        self.assertEqual(result["right"]["left"]["value"], 8)  # 4 * 2
        self.assertEqual(result["right"]["right"]["value"], 7) # 4 + 3
        
        # Проверяем четвертый уровень (левая ветка)
        self.assertEqual(result["left"]["left"]["left"]["value"], 8)   # 4 * 2
        self.assertEqual(result["left"]["left"]["right"]["value"], 7)  # 4 + 3
        self.assertEqual(result["left"]["right"]["left"]["value"], 10) # 5 * 2
        self.assertEqual(result["left"]["right"]["right"]["value"], 8) # 5 + 3
        
        # Проверяем четвертый уровень (правая ветка)
        self.assertEqual(result["right"]["left"]["left"]["value"], 16)  # 8 * 2
        self.assertEqual(result["right"]["left"]["right"]["value"], 11) # 8 + 3
        self.assertEqual(result["right"]["right"]["left"]["value"], 14) # 7 * 2
        self.assertEqual(result["right"]["right"]["right"]["value"], 10) # 7 + 3
    
    

unittest.main()