
class AnonymousSurvey():
    """收集匿名问卷的答案"""

    def __init__(self, question):
        self.question = question
        self.response = []

    def show_question(self):
        print(question)

    def store_response(self, new_resp):
        self.response.append(new_resp)

    def show_results(self):
        print("Survey results:")

        for r in response:
            print("-" + r)
