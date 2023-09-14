/// [Fooling Around](https://open.kattis.com/problems/foolingaround?tab=metadata)
/// **Author:** Danial Haseeb
///
/// Helper file to precompute the set of numbers that Bob wins on.

fn print()
{
	let max = 1_000_000_000;
	let moves = sieve(max);

	let mut alice_wins = vec![false;  max + 1];

	alice_wins[1] = true;
	alice_wins[2] = true;

	for i in 0..=max
	{
		if alice_wins[i]
		{ continue; }

		for candidate_move in &moves
		{
			let candidate_win = i + candidate_move;

			if candidate_win > max
			{ break; }

			alice_wins[candidate_win] = true;
		}

		println!("{i}");
	}
}

fn sieve(n: usize) -> Vec<usize>
{
	let mut isPrime = vec![true; n + 1];

	isPrime[0] = false;
	isPrime[1] = false;

	let root_n = (n as f64).sqrt() as usize;

	for i in 2..=root_n
	{
		if isPrime[i]
		{
			for j in (i*i..=n).step_by(i)
			{ isPrime[j] = false; }
		}
	}

	let mut moves = Vec::new();

	for i in 0..=n
	{
		if isPrime[i]
		{ moves.push(i - 1); }
	}

	moves
}
