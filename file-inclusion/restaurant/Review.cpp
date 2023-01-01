#include "Review.h"
using namespace std;

void Review::SetRatingAndComment(int revRating, string revComment) {
   rating = revRating;
   comment = revComment;
}

int Review::GetRating() const {
   return rating;
}

string Review::GetComment() const {
   return comment;
}