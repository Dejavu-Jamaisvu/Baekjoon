#pragma once // 이게 뭔지 정리!!

#include <assert.h> //예외처리를 위해

// template - 컴파일 단계에서 타입을 직접 지정해 줄 수 있음.(가변 타입)
// 즉, STL 처럼 만들 수 있음 // STL: 템플릿을 이용한 자료구조들을 만들어 놓고 사용자들이 사용하기 편하게 다양한 인터페이스 제공
template <typename T>
class CListNode
{
    template <typename T>
    friend class CLinkedList; // friend - 링크드리스트 클래스에서만 private에 접근할 수 있게 함.

private:
    CListnode()
    {
        m_pNext = nullptr; // 0일때 예외처리하기 쉬움. nullptr로 초기화 해주자
        m_pPrev = nullptr;
    }
    ~CListnode()
    {
    }

private:
    T m_Data;              // 실제 데이터를 저장할 변수
    CListNode<T> *m_pNext; // 다음노드의 주소를 저장할 변수
    CListNode<T> *m_pPrev; // 이전노드의 주소를 저장할 변수
};
// 생성자 소멸자가 private - 외부에서 노드 객체를 생성하는 것을 막기위해.

template <typename T>
class CLinkedList
{
public:
    CLinkedList()
    {
        // begin과 end는 반드시 필요하니 생성자에서 동적할당 해줌
        m_pBegin = new NODE;
        m_pEnd = new NODE;

        // 처음에는 추가된 노드가 없으므로 Begin의 다음으로 End, End 이전으로 Begin 지정.
        m_pBegin->m_pNext = m_pEnd;
        m_pEnd->m_pPrev = m_pBegin;
        m_iSize = 0;
    }
    ~CLinkedList()
    {
        clear();
        delete m_pBegin;
        delete m_pEnd;
        //모든 노드를 제거하여 동적할당된 모든 메모리 제거
    }

private:
    typedef CListNode<T> NODE; // CListNode<T>라는 타입을 NODE로 정의하는 것인듯. 노드의 템플릿타입을 리스트에 들어오는 노드의 T타입으로 작성 - 그냥 일치시켜주란 얘기인 듯
    typedef CListNode<T> *PNODE;

private:
    // 우리는 begin과 end라는 더미 노드를 만들어 놓을 것임. 실제 데이터를 저장하지는 않고 리스트의 시작과 끝을 나타내기만함. 실제 데이터는 이 노드들 사이에 추가 할 것임. 처음엔 이 두개가 서로 연결되어있음
    // 리스트안에 데이터를 넣은 상태에서 리스트 전체에 대한 반복처리를 해야할 경우, 명시적으로 처음과 끝이 존재해서 쉽게 처리 가능
    PNODE m_pBegin;
    PNODE m_pEnd;
    int m_iSize; // 데이터가 몇개가 추가되는지.

public:
    void push_back(const T &data) // const 레퍼런스 타입 - 레퍼런스는 용량 큰 구조체나 클래스 같은 큰 자료형을 받아올 때 참조를 하면 복사보다 빠른 속도로 인자 처리 가능. const는 참조하는 대상의 값을 변경하지 못하게 하기 위함.
    {
        PNODE pNode = new NODE; //???????왜 PNODE 뭐시기 = new NODE; 이렇게 선언해서 쓰는지 생각할 것!!
        pNode->m_Data = data;

        // 뒤에 추가를 해야하므로, End 이전 노드를 얻어옴
        PNODE pPrev = m_pEnd->m_pPrev;

        // 얻어온 이전 노드와 End 노드 사이에 새로 생성한 노드를 추가
        pPrev->m_pNext = pNode; // 이전노드에 다음이 엔드노드로 되어 있는걸 현재노드로 바꿈.
        pNode->m_pPrev = pPrev; // 현재노드의 이전을 End에서 가져온 이전노드로 정해줌.

        // End노드와 새로 생성한 노드를 연결
        pNode->m_pNext = m_pEnd; // 현재노드의 다음을 엔드로 지정함.
        m_pEnd->m_pPrev = pNode; // 엔드의 이전노드를 현재노드로 바꿈.

        ++m_iSize; // 노드 추가 개수 증가해줌
    }
    void push_front(const T &data)
    {
        PNODE pNode = new NODE;
        pNode->m_Data = data;

        // begin과 그 다음 노드 사이에 새로 생성한 노드 추가
        PNODE pNext = m_pBegin->m_pNext;

        // 새로생성한 노드의 다음노드로 begin 의 다음 노드, begin의 다음 노드의 이전노드로 새로생성한 노드 줌.
        pNode->m_pNext = pNext; // 현재생성하는 노드의 다음은 비긴의 다음노드로 정해줌.
        pNext->m_pPrev = pNode; // 다음노드의 이전노드가 비긴으로 있었던걸 새로 생성한 노드로 바꿈.

        // begin의 다음노드로 새로생성한 노드, 새로생성한 노드의 이전노드로 begin 줌.
        m_pBegin->m_pNext = pNode; // 비긴의 다음을 pNode로 바꿈.
        pNode->m_pPrev = m_pBegin; // 현재 노드의 이전을 begin으로 정해줌.

        ++m_iSize; // 노드 추가 개수 증가해줌
    }

    // begin과 end를 제외한 실제 추가한 노드를 전부 삭제하는 기능
    void clear()
    {

    }
    int size() const // 뒤에 콘스트를 붙여서 콘스트 객체에서 사이즈를 호출할 수 있게 함. 단, 이 멤버함수의 값을 변경하는 코드가 들어가면 안됨.
    {
        return m_iSize
    }

    // 리스트가 비어있을 땐 true, 아니면 false
    bool empty() const
    {
        return m_iSize == 0;
    }
};
