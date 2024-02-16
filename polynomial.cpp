#include <iostream>

// Structure to represent a term in a polynomial
struct Term {
    int coefficient;
    int degree;
    Term* next;

    // Constructor
    Term(int coeff, int deg) : coefficient(coeff), degree(deg), next(nullptr) {}
};

// Function to add two polynomials
Term* addPolynomials(Term* poly1, Term* poly2) {
    Term* resultHead = nullptr;
    Term* resultTail = nullptr;

    while (poly1 != nullptr && poly2 != nullptr) {
        Term* term = new Term(0, 0);

        if (poly1->degree == poly2->degree) {
            term->coefficient = poly1->coefficient + poly2->coefficient;
            term->degree = poly1->degree;
            poly1 = poly1->next;
            poly2 = poly2->next;
        } else if (poly1->degree > poly2->degree) {
            term->coefficient = poly1->coefficient;
            term->degree = poly1->degree;
            poly1 = poly1->next;
        } else {
            term->coefficient = poly2->coefficient;
            term->degree = poly2->degree;
            poly2 = poly2->next;
        }

        // Append the term to the result polynomial
        if (resultHead == nullptr) {
            resultHead = term;
            resultTail = term;
        } else {
            resultTail->next = term;
            resultTail = term;
        }
    }

    // Add remaining terms from poly1, if any
    while (poly1 != nullptr) {
        Term* term = new Term(poly1->coefficient, poly1->degree);
        resultTail->next = term;
        resultTail = term;
        poly1 = poly1->next;
    }

    // Add remaining terms from poly2, if any
    while (poly2 != nullptr) {
        Term* term = new Term(poly2->coefficient, poly2->degree);
        resultTail->next = term;
        resultTail = term;
        poly2 = poly2->next;
    }

    return resultHead;
}

// Function to display a polynomial
void displayPolynomial(Term* poly) {
    while (poly != nullptr) {
        std::cout << poly->coefficient << "x^" << poly->degree;
        poly = poly->next;
        if (poly != nullptr) {
            std::cout << " + ";
        }
    }
    std::cout << std::endl;
}

// Function to free memory allocated for a polynomial
void freePolynomial(Term* poly) {
    while (poly != nullptr) {
        Term* temp = poly;
        poly = poly->next;
        delete temp;
    }
}

// Example usage
int main() {
    Term* poly1 = new Term(3, 2);  // 3x^2
    poly1->next = new Term(5, 1);  // 5x
    poly1->next->next = new Term(2, 0);  // 2

    Term* poly2 = new Term(2, 1);  // 2x
    poly2->next = new Term(1, 0);  // 1

    Term* result = addPolynomials(poly1, poly2);

    // Display the result polynomial
    std::cout << "Result: ";
    displayPolynomial(result);

    // Free memory
    freePolynomial(poly1);
    freePolynomial(poly2);
    freePolynomial(result);

    return 0;
}
