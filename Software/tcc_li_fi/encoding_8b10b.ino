#include "encode.h"

void setup8B10B() {

	// rd must be always initilized as negative
	rd = -1;
}

unsigned int encode8B10B(unsigned char data) {

	switch (data) {
		case 0u:
			return (rd < 0 ? 628u : 395u);
			break;
		case 1u:
			return (rd < 0 ? 468u : 555u);
			break;
		case 2u:
			return (rd < 0 ? 724u : 299u);
			break;
		case 3u:
			rd *= -1;
			return (rd > 0 ? 795u : 788u);
			break;
		case 4u:
			return (rd < 0 ? 852u : 171u);
			break;
		case 5u:
			rd *= -1;
			return (rd > 0 ? 667u : 660u);
			break;
		case 6u:
			rd *= -1;
			return (rd > 0 ? 411u : 404u);
			break;
		case 7u:
			rd *= -1;
			return (rd > 0 ? 907u : 116u);
			break;
		case 8u:
			return (rd < 0 ? 916u : 107u);
			break;
		case 9u:
			rd *= -1;
			return (rd > 0 ? 603u : 596u);
			break;
		case 10u:
			rd *= -1;
			return (rd > 0 ? 347u : 340u);
			break;
		case 11u:
			rd *= -1;
			return (rd > 0 ? 843u : 836u);
			break;
		case 12u:
			rd *= -1;
			return (rd > 0 ? 219u : 212u);
			break;
		case 13u:
			rd *= -1;
			return (rd > 0 ? 715u : 708u);
			break;
		case 14u:
			rd *= -1;
			return (rd > 0 ? 459u : 452u);
			break;
		case 15u:
			return (rd < 0 ? 372u : 651u);
			break;
		case 16u:
			return (rd < 0 ? 436u : 587u);
			break;
		case 17u:
			rd *= -1;
			return (rd > 0 ? 571u : 564u);
			break;
		case 18u:
			rd *= -1;
			return (rd > 0 ? 315u : 308u);
			break;
		case 19u:
			rd *= -1;
			return (rd > 0 ? 811u : 804u);
			break;
		case 20u:
			rd *= -1;
			return (rd > 0 ? 187u : 180u);
			break;
		case 21u:
			rd *= -1;
			return (rd > 0 ? 683u : 676u);
			break;
		case 22u:
			rd *= -1;
			return (rd > 0 ? 427u : 420u);
			break;
		case 23u:
			return (rd < 0 ? 932u : 91u);
			break;
		case 24u:
			return (rd < 0 ? 820u : 203u);
			break;
		case 25u:
			rd *= -1;
			return (rd > 0 ? 619u : 612u);
			break;
		case 26u:
			rd *= -1;
			return (rd > 0 ? 363u : 356u);
			break;
		case 27u:
			return (rd < 0 ? 868u : 155u);
			break;
		case 28u:
			rd *= -1;
			return (rd > 0 ? 235u : 228u);
			break;
		case 29u:
			return (rd < 0 ? 740u : 283u);
			break;
		case 30u:
			return (rd < 0 ? 484u : 539u);
			break;
		case 31u:
			return (rd < 0 ? 692u : 331u);
			break;
		case 32u:
			rd *= -1;
			return (rd > 0 ? 633u : 393u);
			break;
		case 33u:
			rd *= -1;
			return (rd > 0 ? 473u : 553u);
			break;
		case 34u:
			rd *= -1;
			return (rd > 0 ? 729u : 297u);
			break;
		case 35u:
			return 793u;
			break;
		case 36u:
			rd *= -1;
			return (rd > 0 ? 857u : 169u);
			break;
		case 37u:
			return 665u;
			break;
		case 38u:
			return 409u;
			break;
		case 39u:
			return (rd < 0 ? 905u : 121u);
			break;
		case 40u:
			rd *= -1;
			return (rd > 0 ? 921u : 105u);
			break;
		case 41u:
			return 601u;
			break;
		case 42u:
			return 345u;
			break;
		case 43u:
			return 841u;
			break;
		case 44u:
			return 217u;
			break;
		case 45u:
			return 713u;
			break;
		case 46u:
			return 457u;
			break;
		case 47u:
			rd *= -1;
			return (rd > 0 ? 377u : 649u);
			break;
		case 48u:
			rd *= -1;
			return (rd > 0 ? 441u : 585u);
			break;
		case 49u:
			return 569u;
			break;
		case 50u:
			return 313u;
			break;
		case 51u:
			return 809u;
			break;
		case 52u:
			return 185u;
			break;
		case 53u:
			return 681u;
			break;
		case 54u:
			return 425u;
			break;
		case 55u:
			rd *= -1;
			return (rd > 0 ? 937u : 89u);
			break;
		case 56u:
			rd *= -1;
			return (rd > 0 ? 825u : 201u);
			break;
		case 57u:
			return 617u;
			break;
		case 58u:
			return 361u;
			break;
		case 59u:
			rd *= -1;
			return (rd > 0 ? 873u : 153u);
			break;
		case 60u:
			return 233u;
			break;
		case 61u:
			rd *= -1;
			return (rd > 0 ? 745u : 281u);
			break;
		case 62u:
			rd *= -1;
			return (rd > 0 ? 489u : 537u);
			break;
		case 63u:
			rd *= -1;
			return (rd > 0 ? 697u : 329u);
			break;
		case 64u:
			rd *= -1;
			return (rd > 0 ? 629u : 389u);
			break;
		case 65u:
			rd *= -1;
			return (rd > 0 ? 469u : 549u);
			break;
		case 66u:
			rd *= -1;
			return (rd > 0 ? 725u : 293u);
			break;
		case 67u:
			return 789u;
			break;
		case 68u:
			rd *= -1;
			return (rd > 0 ? 853u : 165u);
			break;
		case 69u:
			return 661u;
			break;
		case 70u:
			return 405u;
			break;
		case 71u:
			return (rd < 0 ? 901u : 117u);
			break;
		case 72u:
			rd *= -1;
			return (rd > 0 ? 917u : 101u);
			break;
		case 73u:
			return 597u;
			break;
		case 74u:
			return 341u;
			break;
		case 75u:
			return 837u;
			break;
		case 76u:
			return 213u;
			break;
		case 77u:
			return 709u;
			break;
		case 78u:
			return 453u;
			break;
		case 79u:
			rd *= -1;
			return (rd > 0 ? 373u : 645u);
			break;
		case 80u:
			rd *= -1;
			return (rd > 0 ? 437u : 581u);
			break;
		case 81u:
			return 565u;
			break;
		case 82u:
			return 309u;
			break;
		case 83u:
			return 805u;
			break;
		case 84u:
			return 181u;
			break;
		case 85u:
			return 677u;
			break;
		case 86u:
			return 421u;
			break;
		case 87u:
			rd *= -1;
			return (rd > 0 ? 933u : 85u);
			break;
		case 88u:
			rd *= -1;
			return (rd > 0 ? 821u : 197u);
			break;
		case 89u:
			return 613u;
			break;
		case 90u:
			return 357u;
			break;
		case 91u:
			rd *= -1;
			return (rd > 0 ? 869u : 149u);
			break;
		case 92u:
			return 229u;
			break;
		case 93u:
			rd *= -1;
			return (rd > 0 ? 741u : 277u);
			break;
		case 94u:
			rd *= -1;
			return (rd > 0 ? 485u : 533u);
			break;
		case 95u:
			rd *= -1;
			return (rd > 0 ? 693u : 325u);
			break;
		case 96u:
			rd *= -1;
			return (rd > 0 ? 627u : 396u);
			break;
		case 97u:
			rd *= -1;
			return (rd > 0 ? 467u : 556u);
			break;
		case 98u:
			rd *= -1;
			return (rd > 0 ? 723u : 300u);
			break;
		case 99u:
			return (rd < 0 ? 796u : 787u);
			break;
		case 100u:
			rd *= -1;
			return (rd > 0 ? 851u : 172u);
			break;
		case 101u:
			return (rd < 0 ? 668u : 659u);
			break;
		case 102u:
			return (rd < 0 ? 412u : 403u);
			break;
		case 103u:
			return (rd < 0 ? 908u : 115u);
			break;
		case 104u:
			rd *= -1;
			return (rd > 0 ? 915u : 108u);
			break;
		case 105u:
			return (rd < 0 ? 604u : 595u);
			break;
		case 106u:
			return (rd < 0 ? 348u : 339u);
			break;
		case 107u:
			return (rd < 0 ? 844u : 835u);
			break;
		case 108u:
			return (rd < 0 ? 220u : 211u);
			break;
		case 109u:
			return (rd < 0 ? 716u : 707u);
			break;
		case 110u:
			return (rd < 0 ? 460u : 451u);
			break;
		case 111u:
			rd *= -1;
			return (rd > 0 ? 371u : 652u);
			break;
		case 112u:
			rd *= -1;
			return (rd > 0 ? 435u : 588u);
			break;
		case 113u:
			return (rd < 0 ? 572u : 563u);
			break;
		case 114u:
			return (rd < 0 ? 316u : 307u);
			break;
		case 115u:
			return (rd < 0 ? 812u : 803u);
			break;
		case 116u:
			return (rd < 0 ? 188u : 179u);
			break;
		case 117u:
			return (rd < 0 ? 684u : 675u);
			break;
		case 118u:
			return (rd < 0 ? 428u : 419u);
			break;
		case 119u:
			rd *= -1;
			return (rd > 0 ? 931u : 92u);
			break;
		case 120u:
			rd *= -1;
			return (rd > 0 ? 819u : 204u);
			break;
		case 121u:
			return (rd < 0 ? 620u : 611u);
			break;
		case 122u:
			return (rd < 0 ? 364u : 355u);
			break;
		case 123u:
			rd *= -1;
			return (rd > 0 ? 867u : 156u);
			break;
		case 124u:
			return (rd < 0 ? 236u : 227u);
			break;
		case 125u:
			rd *= -1;
			return (rd > 0 ? 739u : 284u);
			break;
		case 126u:
			rd *= -1;
			return (rd > 0 ? 483u : 540u);
			break;
		case 127u:
			rd *= -1;
			return (rd > 0 ? 691u : 332u);
			break;
		case 128u:
			return (rd < 0 ? 626u : 397u);
			break;
		case 129u:
			return (rd < 0 ? 466u : 557u);
			break;
		case 130u:
			return (rd < 0 ? 722u : 301u);
			break;
		case 131u:
			rd *= -1;
			return (rd > 0 ? 797u : 786u);
			break;
		case 132u:
			return (rd < 0 ? 850u : 173u);
			break;
		case 133u:
			rd *= -1;
			return (rd > 0 ? 669u : 658u);
			break;
		case 134u:
			rd *= -1;
			return (rd > 0 ? 413u : 402u);
			break;
		case 135u:
			rd *= -1;
			return (rd > 0 ? 909u : 114u);
			break;
		case 136u:
			return (rd < 0 ? 914u : 109u);
			break;
		case 137u:
			rd *= -1;
			return (rd > 0 ? 605u : 594u);
			break;
		case 138u:
			rd *= -1;
			return (rd > 0 ? 349u : 338u);
			break;
		case 139u:
			rd *= -1;
			return (rd > 0 ? 845u : 834u);
			break;
		case 140u:
			rd *= -1;
			return (rd > 0 ? 221u : 210u);
			break;
		case 141u:
			rd *= -1;
			return (rd > 0 ? 717u : 706u);
			break;
		case 142u:
			rd *= -1;
			return (rd > 0 ? 461u : 450u);
			break;
		case 143u:
			return (rd < 0 ? 370u : 653u);
			break;
		case 144u:
			return (rd < 0 ? 434u : 589u);
			break;
		case 145u:
			rd *= -1;
			return (rd > 0 ? 573u : 562u);
			break;
		case 146u:
			rd *= -1;
			return (rd > 0 ? 317u : 306u);
			break;
		case 147u:
			rd *= -1;
			return (rd > 0 ? 813u : 802u);
			break;
		case 148u:
			rd *= -1;
			return (rd > 0 ? 189u : 178u);
			break;
		case 149u:
			rd *= -1;
			return (rd > 0 ? 685u : 674u);
			break;
		case 150u:
			rd *= -1;
			return (rd > 0 ? 429u : 418u);
			break;
		case 151u:
			return (rd < 0 ? 930u : 93u);
			break;
		case 152u:
			return (rd < 0 ? 818u : 205u);
			break;
		case 153u:
			rd *= -1;
			return (rd > 0 ? 621u : 610u);
			break;
		case 154u:
			rd *= -1;
			return (rd > 0 ? 365u : 354u);
			break;
		case 155u:
			return (rd < 0 ? 866u : 157u);
			break;
		case 156u:
			rd *= -1;
			return (rd > 0 ? 237u : 226u);
			break;
		case 157u:
			return (rd < 0 ? 738u : 285u);
			break;
		case 158u:
			return (rd < 0 ? 482u : 541u);
			break;
		case 159u:
			return (rd < 0 ? 690u : 333u);
			break;
		case 160u:
			rd *= -1;
			return (rd > 0 ? 634u : 394u);
			break;
		case 161u:
			rd *= -1;
			return (rd > 0 ? 474u : 554u);
			break;
		case 162u:
			rd *= -1;
			return (rd > 0 ? 730u : 298u);
			break;
		case 163u:
			return 794u;
			break;
		case 164u:
			rd *= -1;
			return (rd > 0 ? 858u : 170u);
			break;
		case 165u:
			return 666u;
			break;
		case 166u:
			return 410u;
			break;
		case 167u:
			return (rd < 0 ? 906u : 122u);
			break;
		case 168u:
			rd *= -1;
			return (rd > 0 ? 922u : 106u);
			break;
		case 169u:
			return 602u;
			break;
		case 170u:
			return 346u;
			break;
		case 171u:
			return 842u;
			break;
		case 172u:
			return 218u;
			break;
		case 173u:
			return 714u;
			break;
		case 174u:
			return 458u;
			break;
		case 175u:
			rd *= -1;
			return (rd > 0 ? 378u : 650u);
			break;
		case 176u:
			rd *= -1;
			return (rd > 0 ? 442u : 586u);
			break;
		case 177u:
			return 570u;
			break;
		case 178u:
			return 314u;
			break;
		case 179u:
			return 810u;
			break;
		case 180u:
			return 186u;
			break;
		case 181u:
			return 682u;
			break;
		case 182u:
			return 426u;
			break;
		case 183u:
			rd *= -1;
			return (rd > 0 ? 938u : 90u);
			break;
		case 184u:
			rd *= -1;
			return (rd > 0 ? 826u : 202u);
			break;
		case 185u:
			return 618u;
			break;
		case 186u:
			return 362u;
			break;
		case 187u:
			rd *= -1;
			return (rd > 0 ? 874u : 154u);
			break;
		case 188u:
			return 234u;
			break;
		case 189u:
			rd *= -1;
			return (rd > 0 ? 746u : 282u);
			break;
		case 190u:
			rd *= -1;
			return (rd > 0 ? 490u : 538u);
			break;
		case 191u:
			rd *= -1;
			return (rd > 0 ? 698u : 330u);
			break;
		case 192u:
			rd *= -1;
			return (rd > 0 ? 630u : 390u);
			break;
		case 193u:
			rd *= -1;
			return (rd > 0 ? 470u : 550u);
			break;
		case 194u:
			rd *= -1;
			return (rd > 0 ? 726u : 294u);
			break;
		case 195u:
			return 790u;
			break;
		case 196u:
			rd *= -1;
			return (rd > 0 ? 854u : 166u);
			break;
		case 197u:
			return 662u;
			break;
		case 198u:
			return 406u;
			break;
		case 199u:
			return (rd < 0 ? 902u : 118u);
			break;
		case 200u:
			rd *= -1;
			return (rd > 0 ? 918u : 102u);
			break;
		case 201u:
			return 598u;
			break;
		case 202u:
			return 342u;
			break;
		case 203u:
			return 838u;
			break;
		case 204u:
			return 214u;
			break;
		case 205u:
			return 710u;
			break;
		case 206u:
			return 454u;
			break;
		case 207u:
			rd *= -1;
			return (rd > 0 ? 374u : 646u);
			break;
		case 208u:
			rd *= -1;
			return (rd > 0 ? 438u : 582u);
			break;
		case 209u:
			return 566u;
			break;
		case 210u:
			return 310u;
			break;
		case 211u:
			return 806u;
			break;
		case 212u:
			return 182u;
			break;
		case 213u:
			return 678u;
			break;
		case 214u:
			return 422u;
			break;
		case 215u:
			rd *= -1;
			return (rd > 0 ? 934u : 86u);
			break;
		case 216u:
			rd *= -1;
			return (rd > 0 ? 822u : 198u);
			break;
		case 217u:
			return 614u;
			break;
		case 218u:
			return 358u;
			break;
		case 219u:
			rd *= -1;
			return (rd > 0 ? 870u : 150u);
			break;
		case 220u:
			return 230u;
			break;
		case 221u:
			rd *= -1;
			return (rd > 0 ? 742u : 278u);
			break;
		case 222u:
			rd *= -1;
			return (rd > 0 ? 486u : 534u);
			break;
		case 223u:
			rd *= -1;
			return (rd > 0 ? 694u : 326u);
			break;
		case 224u:
			return (rd < 0 ? 625u : 398u);
			break;
		case 225u:
			return (rd < 0 ? 465u : 558u);
			break;
		case 226u:
			return (rd < 0 ? 721u : 302u);
			break;
		case 227u:
			rd *= -1;
			return (rd > 0 ? 798u : 785u);
			break;
		case 228u:
			return (rd < 0 ? 849u : 174u);
			break;
		case 229u:
			rd *= -1;
			return (rd > 0 ? 670u : 657u);
			break;
		case 230u:
			rd *= -1;
			return (rd > 0 ? 414u : 401u);
			break;
		case 231u:
			rd *= -1;
			return (rd > 0 ? 910u : 113u);
			break;
		case 232u:
			return (rd < 0 ? 913u : 110u);
			break;
		case 233u:
			rd *= -1;
			return (rd > 0 ? 606u : 593u);
			break;
		case 234u:
			rd *= -1;
			return (rd > 0 ? 350u : 337u);
			break;
		case 235u:
			rd *= -1;
			return (rd > 0 ? 846u : 840u);
			break;
		case 236u:
			rd *= -1;
			return (rd > 0 ? 222u : 209u);
			break;
		case 237u:
			rd *= -1;
			return (rd > 0 ? 718u : 712u);
			break;
		case 238u:
			rd *= -1;
			return (rd > 0 ? 462u : 456u);
			break;
		case 239u:
			return (rd < 0 ? 369u : 654u);
			break;
		case 240u:
			return (rd < 0 ? 433u : 590u);
			break;
		case 241u:
			rd *= -1;
			return (rd > 0 ? 567u : 561u);
			break;
		case 242u:
			rd *= -1;
			return (rd > 0 ? 311u : 305u);
			break;
		case 243u:
			rd *= -1;
			return (rd > 0 ? 814u : 801u);
			break;
		case 244u:
			rd *= -1;
			return (rd > 0 ? 183u : 177u);
			break;
		case 245u:
			rd *= -1;
			return (rd > 0 ? 686u : 673u);
			break;
		case 246u:
			rd *= -1;
			return (rd > 0 ? 430u : 417u);
			break;
		case 247u:
			return (rd < 0 ? 929u : 94u);
			break;
		case 248u:
			return (rd < 0 ? 817u : 206u);
			break;
		case 249u:
			rd *= -1;
			return (rd > 0 ? 622u : 609u);
			break;
		case 250u:
			rd *= -1;
			return (rd > 0 ? 366u : 353u);
			break;
		case 251u:
			return (rd < 0 ? 865u : 158u);
			break;
		case 252u:
			rd *= -1;
			return (rd > 0 ? 238u : 225u);
			break;
		case 253u:
			return (rd < 0 ? 737u : 286u);
			break;
		case 254u:
			return (rd < 0 ? 481u : 542u);
			break;
		case 255u:
			return (rd < 0 ? 689u : 334u);
			break;
		default:
			return 0x3FF; // 10-bit integer: 0011 1111 1111
			break;
	}
}

unsigned char decode8B10B(unsigned int data) {

	switch (data) {
		case 628u:
		case 395u:
			return 0u;
			break;
		case 468u:
		case 555u:
			return 1u;
			break;
		case 724u:
		case 299u:
			return 2u;
			break;
		case 795u:
		case 788u:
			return 3u;
			break;
		case 852u:
		case 171u:
			return 4u;
			break;
		case 667u:
		case 660u:
			return 5u;
			break;
		case 411u:
		case 404u:
			return 6u;
			break;
		case 907u:
		case 116u:
			return 7u;
			break;
		case 916u:
		case 107u:
			return 8u;
			break;
		case 603u:
		case 596u:
			return 9u;
			break;
		case 347u:
		case 340u:
			return 10u;
			break;
		case 843u:
		case 836u:
			return 11u;
			break;
		case 219u:
		case 212u:
			return 12u;
			break;
		case 715u:
		case 708u:
			return 13u;
			break;
		case 459u:
		case 452u:
			return 14u;
			break;
		case 372u:
		case 651u:
			return 15u;
			break;
		case 436u:
		case 587u:
			return 16u;
			break;
		case 571u:
		case 564u:
			return 17u;
			break;
		case 315u:
		case 308u:
			return 18u;
			break;
		case 811u:
		case 804u:
			return 19u;
			break;
		case 187u:
		case 180u:
			return 20u;
			break;
		case 683u:
		case 676u:
			return 21u;
			break;
		case 427u:
		case 420u:
			return 22u;
			break;
		case 932u:
		case 91u:
			return 23u;
			break;
		case 820u:
		case 203u:
			return 24u;
			break;
		case 619u:
		case 612u:
			return 25u;
			break;
		case 363u:
		case 356u:
			return 26u;
			break;
		case 868u:
		case 155u:
			return 27u;
			break;
		case 235u:
		case 228u:
			return 28u;
			break;
		case 740u:
		case 283u:
			return 29u;
			break;
		case 484u:
		case 539u:
			return 30u;
			break;
		case 692u:
		case 331u:
			return 31u;
			break;
		case 633u:
		case 393u:
			return 32u;
			break;
		case 473u:
		case 553u:
			return 33u;
			break;
		case 729u:
		case 297u:
			return 34u;
			break;
		case 793u:
			return 35u;
			break;
		case 857u:
		case 169u:
			return 36u;
			break;
		case 665u:
			return 37u;
			break;
		case 409u:
			return 38u;
			break;
		case 905u:
		case 121u:
			return 39u;
			break;
		case 921u:
		case 105u:
			return 40u;
			break;
		case 601u:
			return 41u;
			break;
		case 345u:
			return 42u;
			break;
		case 841u:
			return 43u;
			break;
		case 217u:
			return 44u;
			break;
		case 713u:
			return 45u;
			break;
		case 457u:
			return 46u;
			break;
		case 377u:
		case 649u:
			return 47u;
			break;
		case 441u:
		case 585u:
			return 48u;
			break;
		case 569u:
			return 49u;
			break;
		case 313u:
			return 50u;
			break;
		case 809u:
			return 51u;
			break;
		case 185u:
			return 52u;
			break;
		case 681u:
			return 53u;
			break;
		case 425u:
			return 54u;
			break;
		case 937u:
		case 89u:
			return 55u;
			break;
		case 825u:
		case 201u:
			return 56u;
			break;
		case 617u:
			return 57u;
			break;
		case 361u:
			return 58u;
			break;
		case 873u:
		case 153u:
			return 59u;
			break;
		case 233u:
			return 60u;
			break;
		case 745u:
		case 281u:
			return 61u;
			break;
		case 489u:
		case 537u:
			return 62u;
			break;
		case 697u:
		case 329u:
			return 63u;
			break;
		case 629u:
		case 389u:
			return 64u;
			break;
		case 469u:
		case 549u:
			return 65u;
			break;
		case 725u:
		case 293u:
			return 66u;
			break;
		case 789u:
			return 67u;
			break;
		case 853u:
		case 165u:
			return 68u;
			break;
		case 661u:
			return 69u;
			break;
		case 405u:
			return 70u;
			break;
		case 901u:
		case 117u:
			return 71u;
			break;
		case 917u:
		case 101u:
			return 72u;
			break;
		case 597u:
			return 73u;
			break;
		case 341u:
			return 74u;
			break;
		case 837u:
			return 75u;
			break;
		case 213u:
			return 76u;
			break;
		case 709u:
			return 77u;
			break;
		case 453u:
			return 78u;
			break;
		case 373u:
		case 645u:
			return 79u;
			break;
		case 437u:
		case 581u:
			return 80u;
			break;
		case 565u:
			return 81u;
			break;
		case 309u:
			return 82u;
			break;
		case 805u:
			return 83u;
			break;
		case 181u:
			return 84u;
			break;
		case 677u:
			return 85u;
			break;
		case 421u:
			return 86u;
			break;
		case 933u:
		case 85u:
			return 87u;
			break;
		case 821u:
		case 197u:
			return 88u;
			break;
		case 613u:
			return 89u;
			break;
		case 357u:
			return 90u;
			break;
		case 869u:
		case 149u:
			return 91u;
			break;
		case 229u:
			return 92u;
			break;
		case 741u:
		case 277u:
			return 93u;
			break;
		case 485u:
		case 533u:
			return 94u;
			break;
		case 693u:
		case 325u:
			return 95u;
			break;
		case 627u:
		case 396u:
			return 96u;
			break;
		case 467u:
		case 556u:
			return 97u;
			break;
		case 723u:
		case 300u:
			return 98u;
			break;
		case 796u:
		case 787u:
			return 99u;
			break;
		case 851u:
		case 172u:
			return 100u;
			break;
		case 668u:
		case 659u:
			return 101u;
			break;
		case 412u:
		case 403u:
			return 102u;
			break;
		case 908u:
		case 115u:
			return 103u;
			break;
		case 915u:
		case 108u:
			return 104u;
			break;
		case 604u:
		case 595u:
			return 105u;
			break;
		case 348u:
		case 339u:
			return 106u;
			break;
		case 844u:
		case 835u:
			return 107u;
			break;
		case 220u:
		case 211u:
			return 108u;
			break;
		case 716u:
		case 707u:
			return 109u;
			break;
		case 460u:
		case 451u:
			return 110u;
			break;
		case 371u:
		case 652u:
			return 111u;
			break;
		case 435u:
		case 588u:
			return 112u;
			break;
		case 572u:
		case 563u:
			return 113u;
			break;
		case 316u:
		case 307u:
			return 114u;
			break;
		case 812u:
		case 803u:
			return 115u;
			break;
		case 188u:
		case 179u:
			return 116u;
			break;
		case 684u:
		case 675u:
			return 117u;
			break;
		case 428u:
		case 419u:
			return 118u;
			break;
		case 931u:
		case 92u:
			return 119u;
			break;
		case 819u:
		case 204u:
			return 120u;
			break;
		case 620u:
		case 611u:
			return 121u;
			break;
		case 364u:
		case 355u:
			return 122u;
			break;
		case 867u:
		case 156u:
			return 123u;
			break;
		case 236u:
		case 227u:
			return 124u;
			break;
		case 739u:
		case 284u:
			return 125u;
			break;
		case 483u:
		case 540u:
			return 126u;
			break;
		case 691u:
		case 332u:
			return 127u;
			break;
		case 626u:
		case 397u:
			return 128u;
			break;
		case 466u:
		case 557u:
			return 129u;
			break;
		case 722u:
		case 301u:
			return 130u;
			break;
		case 797u:
		case 786u:
			return 131u;
			break;
		case 850u:
		case 173u:
			return 132u;
			break;
		case 669u:
		case 658u:
			return 133u;
			break;
		case 413u:
		case 402u:
			return 134u;
			break;
		case 909u:
		case 114u:
			return 135u;
			break;
		case 914u:
		case 109u:
			return 136u;
			break;
		case 605u:
		case 594u:
			return 137u;
			break;
		case 349u:
		case 338u:
			return 138u;
			break;
		case 845u:
		case 834u:
			return 139u;
			break;
		case 221u:
		case 210u:
			return 140u;
			break;
		case 717u:
		case 706u:
			return 141u;
			break;
		case 461u:
		case 450u:
			return 142u;
			break;
		case 370u:
		case 653u:
			return 143u;
			break;
		case 434u:
		case 589u:
			return 144u;
			break;
		case 573u:
		case 562u:
			return 145u;
			break;
		case 317u:
		case 306u:
			return 146u;
			break;
		case 813u:
		case 802u:
			return 147u;
			break;
		case 189u:
		case 178u:
			return 148u;
			break;
		case 685u:
		case 674u:
			return 149u;
			break;
		case 429u:
		case 418u:
			return 150u;
			break;
		case 930u:
		case 93u:
			return 151u;
			break;
		case 818u:
		case 205u:
			return 152u;
			break;
		case 621u:
		case 610u:
			return 153u;
			break;
		case 365u:
		case 354u:
			return 154u;
			break;
		case 866u:
		case 157u:
			return 155u;
			break;
		case 237u:
		case 226u:
			return 156u;
			break;
		case 738u:
		case 285u:
			return 157u;
			break;
		case 482u:
		case 541u:
			return 158u;
			break;
		case 690u:
		case 333u:
			return 159u;
			break;
		case 634u:
		case 394u:
			return 160u;
			break;
		case 474u:
		case 554u:
			return 161u;
			break;
		case 730u:
		case 298u:
			return 162u;
			break;
		case 794u:
			return 163u;
			break;
		case 858u:
		case 170u:
			return 164u;
			break;
		case 666u:
			return 165u;
			break;
		case 410u:
			return 166u;
			break;
		case 906u:
		case 122u:
			return 167u;
			break;
		case 922u:
		case 106u:
			return 168u;
			break;
		case 602u:
			return 169u;
			break;
		case 346u:
			return 170u;
			break;
		case 842u:
			return 171u;
			break;
		case 218u:
			return 172u;
			break;
		case 714u:
			return 173u;
			break;
		case 458u:
			return 174u;
			break;
		case 378u:
		case 650u:
			return 175u;
			break;
		case 442u:
		case 586u:
			return 176u;
			break;
		case 570u:
			return 177u;
			break;
		case 314u:
			return 178u;
			break;
		case 810u:
			return 179u;
			break;
		case 186u:
			return 180u;
			break;
		case 682u:
			return 181u;
			break;
		case 426u:
			return 182u;
			break;
		case 938u:
		case 90u:
			return 183u;
			break;
		case 826u:
		case 202u:
			return 184u;
			break;
		case 618u:
			return 185u;
			break;
		case 362u:
			return 186u;
			break;
		case 874u:
		case 154u:
			return 187u;
			break;
		case 234u:
			return 188u;
			break;
		case 746u:
		case 282u:
			return 189u;
			break;
		case 490u:
		case 538u:
			return 190u;
			break;
		case 698u:
		case 330u:
			return 191u;
			break;
		case 630u:
		case 390u:
			return 192u;
			break;
		case 470u:
		case 550u:
			return 193u;
			break;
		case 726u:
		case 294u:
			return 194u;
			break;
		case 790u:
			return 195u;
			break;
		case 854u:
		case 166u:
			return 196u;
			break;
		case 662u:
			return 197u;
			break;
		case 406u:
			return 198u;
			break;
		case 902u:
		case 118u:
			return 199u;
			break;
		case 918u:
		case 102u:
			return 200u;
			break;
		case 598u:
			return 201u;
			break;
		case 342u:
			return 202u;
			break;
		case 838u:
			return 203u;
			break;
		case 214u:
			return 204u;
			break;
		case 710u:
			return 205u;
			break;
		case 454u:
			return 206u;
			break;
		case 374u:
		case 646u:
			return 207u;
			break;
		case 438u:
		case 582u:
			return 208u;
			break;
		case 566u:
			return 209u;
			break;
		case 310u:
			return 210u;
			break;
		case 806u:
			return 211u;
			break;
		case 182u:
			return 212u;
			break;
		case 678u:
			return 213u;
			break;
		case 422u:
			return 214u;
			break;
		case 934u:
		case 86u:
			return 215u;
			break;
		case 822u:
		case 198u:
			return 216u;
			break;
		case 614u:
			return 217u;
			break;
		case 358u:
			return 218u;
			break;
		case 870u:
		case 150u:
			return 219u;
			break;
		case 230u:
			return 220u;
			break;
		case 742u:
		case 278u:
			return 221u;
			break;
		case 486u:
		case 534u:
			return 222u;
			break;
		case 694u:
		case 326u:
			return 223u;
			break;
		case 625u:
		case 398u:
			return 224u;
			break;
		case 465u:
		case 558u:
			return 225u;
			break;
		case 721u:
		case 302u:
			return 226u;
			break;
		case 798u:
		case 785u:
			return 227u;
			break;
		case 849u:
		case 174u:
			return 228u;
			break;
		case 670u:
		case 657u:
			return 229u;
			break;
		case 414u:
		case 401u:
			return 230u;
			break;
		case 910u:
		case 113u:
			return 231u;
			break;
		case 913u:
		case 110u:
			return 232u;
			break;
		case 606u:
		case 593u:
			return 233u;
			break;
		case 350u:
		case 337u:
			return 234u;
			break;
		case 846u:
		case 840u:
			return 235u;
			break;
		case 222u:
		case 209u:
			return 236u;
			break;
		case 718u:
		case 712u:
			return 237u;
			break;
		case 462u:
		case 456u:
			return 238u;
			break;
		case 369u:
		case 654u:
			return 239u;
			break;
		case 433u:
		case 590u:
			return 240u;
			break;
		case 567u:
		case 561u:
			return 241u;
			break;
		case 311u:
		case 305u:
			return 242u;
			break;
		case 814u:
		case 801u:
			return 243u;
			break;
		case 183u:
		case 177u:
			return 244u;
			break;
		case 686u:
		case 673u:
			return 245u;
			break;
		case 430u:
		case 417u:
			return 246u;
			break;
		case 929u:
		case 94u:
			return 247u;
			break;
		case 817u:
		case 206u:
			return 248u;
			break;
		case 622u:
		case 609u:
			return 249u;
			break;
		case 366u:
		case 353u:
			return 250u;
			break;
		case 865u:
		case 158u:
			return 251u;
			break;
		case 238u:
		case 225u:
			return 252u;
			break;
		case 737u:
		case 286u:
			return 253u;
			break;
		case 481u:
		case 542u:
			return 254u;
			break;
		case 689u:
		case 334u:
			return 255u;
			break;
	}
}
