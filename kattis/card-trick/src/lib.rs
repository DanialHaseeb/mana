/// [Card Trick](https://open.kattis.com/problems/cardtrick2?tab=metadata)
/// **Author:** Danial Haseeb
///
/// Helper file to precalculate the permutations of the card trick.

use std::collections::VecDeque;

fn print()
{
	for i in 1..=13
	{
		let mut deck = VecDeque::new();
		let mut card = i;
		deck.push_back(card);
		card -= 1;

		while card != 0
		{
			deck.push_back(card);

			for _ in 0..card
			{
				let temporary = deck.pop_front().unwrap();
				deck.push_back(temporary);
			}

			card -= 1;
		}

		print!("\"");
		for j in (1..=i-1).rev()
		{ print!("{} ", deck[j]); }
		println!("{}\",", deck[0]);
	}
}
