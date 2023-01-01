#ifndef REVIEW_H
#define REVIEW_H

#include <string>

class Review {
   public:
      void SetRatingAndComment(
         int revRating,
         std::string revComment);
      int GetRating() const;
      std::string GetComment() const;

   private:
      int rating = -1;
      std::string comment = "NoComment";
};

#endif