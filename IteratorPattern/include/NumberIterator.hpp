#include <iostream>
#include <vector>

class NumberIterator {
public:
    virtual ~NumberIterator(){};
    virtual int& next() = 0;
    virtual bool isFinished() = 0;
};

class BackwardIterator : public NumberIterator {
    int m_currentPosition;
    std::vector<int>& m_numbers;
    
public:
    BackwardIterator(std::vector<int>& numbers) 
        : m_numbers(numbers), m_currentPosition(0) {}

    int& next() override {
        int& current = m_numbers.at(m_numbers.size() - m_currentPosition - 1);
        m_currentPosition += 1;
        return current;
    }

    bool isFinished() override {
        return m_currentPosition >= m_numbers.size();
    }
};

class ForwardIterator : public NumberIterator {
    int m_currentPosition;
    std::vector<int>& m_numbers;

public:
    ForwardIterator(std::vector<int>& numbers) 
        : m_numbers(numbers), m_currentPosition(0) {}

    int& next() override {
        int& current = m_numbers.at(m_currentPosition);
        m_currentPosition += 1;
        return current;
    }

    bool isFinished() override {
        return m_currentPosition >= m_numbers.size();
    }
};


class NumberCollection {
    std::vector<int> m_numbers;
public:
    NumberCollection(std::vector<int> numbers):m_numbers(numbers){};
    ForwardIterator* getForwardIterator() {
        return new ForwardIterator(m_numbers);
    }

    BackwardIterator* getBackwardIterator() {
        return new BackwardIterator(m_numbers);
    }
};
