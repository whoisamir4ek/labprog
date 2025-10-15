import unittest
from lr2 import resh

class TestTwoSum(unittest.TestCase):
    
    def test_basic_case(self):
        self.assertEqual(resh([2, 7, 11, 15], 9), [0, 1])
    
    def test_negative_numbers(self):
        self.assertEqual(resh([-3, 4, 3, 90], 0), [0, 2])
    
    def test_duplicate_numbers(self):
        self.assertEqual(resh([3, 3], 6), [0, 1])
    
    def test_no_solution(self):
        self.assertEqual(resh([1, 2, 3], 7), [])
    
    def test_larger_array(self):
        self.assertEqual(resh([1, 5, 8, 12, 3, 7], 10), [4, 5])
    
    def test_single_element(self):
        self.assertEqual(resh([5], 5), [])
    
    def test_empty_array(self):
        self.assertEqual(resh([], 5), [])

unittest.main(argv=[''], verbosity=2, exit=False)
