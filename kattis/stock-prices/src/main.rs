/// [Stock Prices](https://open.kattis.com/problems/stockprices)
/// **Author:** Danial Haseeb

use std::io;
use std::collections::BTreeMap;
use std::cmp::Ordering;

fn main()
{
	let mut input = io::stdin().lines();

	let cases: u8 = input.next().unwrap().unwrap().parse().unwrap();

	let mut asks = BTreeMap::new();
	let mut bids = BTreeMap::new();
	let mut trade_price = None;

	for _ in 0..cases
	{
		let n: u16 = input.next().unwrap().unwrap().trim().parse().unwrap();

		for _ in 0..n
		{
			let line = input.next().unwrap().unwrap();
			let (order_type, remainder) = line.split_once(' ').unwrap();
			let (quantity, price) = remainder.split_once(" shares at ").unwrap();
			let order = Order::parse(order_type, quantity, price);

			match order
			{
				Order::Buy(quantity, price ) =>
				{ *bids.entry(price).or_insert(0) += quantity; }
				Order::Sell(quantity, price) =>
				{ *asks.entry(price).or_insert(0) += quantity; }
			}

			while let
			(
				Some((&bid_price, &bid_quantity)),
				Some((&ask_price, &ask_quantity))
			) = (bids.iter().rev().next(), asks.iter().next())
			{
				if bid_price < ask_price
				{ break; }

				trade_price = Some(ask_price);

				match bid_quantity.cmp(&ask_quantity)
				{
					Ordering::Less =>
					{
						*asks.get_mut(&ask_price).unwrap() -= bid_quantity;
						bids.remove(&bid_price);
					}
					Ordering::Equal =>
					{
						bids.remove(&bid_price);
						asks.remove(&ask_price);
					}
					Ordering::Greater =>
					{
						*bids.get_mut(&bid_price).unwrap() -= ask_quantity;
						asks.remove(&ask_price);
					}
				}
			}

			if let Some((a, _)) = asks.iter().next()
			{ print!("{a} "); }
			else
			{ print!("- "); }

			if let Some((b, _)) = bids.iter().rev().next()
			{ print!("{b} "); }
			else
			{ print!("- "); }

			if let Some(s) = trade_price
			{ println!("{s}"); }
			else
			{ println!("-"); }
		}

		asks.clear();
		bids.clear();
		trade_price = None;
	}
}

enum Order
{
	Buy(u16, u16),
	Sell(u16, u16)
}

impl Order
{
	fn parse(order_type: &str, quantity: &str, price: &str) -> Self
	{
		let quantity: u16 = quantity.parse().unwrap();
		let price: u16 = price.parse().unwrap();

		match order_type
		{
			"buy" => Self::Buy(quantity, price),
			"sell" => Self::Sell(quantity, price),
			_ => unreachable!()
		}
	}
}
