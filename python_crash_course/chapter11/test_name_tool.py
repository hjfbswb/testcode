import unittest
from name_tool import format_name

class NameToolTestCase(unittest.TestCase):
    """测试name_tool.py"""

    def test_first_last_name(self):
        formated = format_name("janis", "joplin")
        self.assertEqual(formated, "Janis Joplin")

    def test_first_last_middle_name(self):
        formated = format_name("wolfgang", 'mozart', 'amadeus')
        self.assertEqual(formated, "Wolfgang Amadeus Mozart")


unittest.main()
