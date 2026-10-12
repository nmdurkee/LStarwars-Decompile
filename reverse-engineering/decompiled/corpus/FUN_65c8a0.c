/* Ghidra analysis pseudocode, not original source.
 * ev_72b4c015fc5ea067bd8ff7b23618dfd066d3174eed64a8765571f91528d681aa
 * Entry: 0x65c8a0; label: FUN_0065c8a0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0065c8a0(void)

{
  if (DAT_02962934 != 0) {
    if (DAT_02962938 == 0) {
      DAT_02962938 = FUN_005d5330();
    }
    *(undefined4 *)(DAT_02962938 + 0x40) = _DAT_00810a20;
    *(undefined4 *)(DAT_02962938 + 0x44) = _DAT_00810a24;
    switch(DAT_02962934) {
    case 1:
      FUN_00617e30(0);
      _DAT_0097392c = 0;
      break;
    case 5:
      FUN_0065c7b0(5);
      DAT_02962934 = DAT_02962934 + -1;
      return;
    case 10:
      FUN_00620f40(0,0x8000);
      FUN_00621140();
      DAT_02962934 = DAT_02962934 + -1;
      return;
    case 0xf:
      FUN_0065c7b0(4);
      DAT_02962934 = DAT_02962934 + -1;
      return;
    case 0x14:
      FUN_00620f40(0,0);
      FUN_00621140();
      DAT_02962934 = DAT_02962934 + -1;
      return;
    case 0x19:
      FUN_0065c7b0(3);
      DAT_02962934 = DAT_02962934 + -1;
      return;
    case 0x1e:
      FUN_00620f40(0x4000,0);
      FUN_00621140();
      DAT_02962934 = DAT_02962934 + -1;
      return;
    case 0x23:
      FUN_0065c7b0(2);
      DAT_02962934 = DAT_02962934 + -1;
      return;
    case 0x28:
      FUN_00620f40(0xffffc000,0);
      FUN_00621140();
      DAT_02962934 = DAT_02962934 + -1;
      return;
    case 0x2d:
      FUN_0065c7b0(1);
      DAT_02962934 = DAT_02962934 + -1;
      return;
    case 0x32:
      FUN_00620f40(0,0xc000);
      FUN_00621140();
      DAT_02962934 = DAT_02962934 + -1;
      return;
    case 0x37:
      FUN_0065c7b0(0);
      DAT_02962934 = DAT_02962934 + -1;
      return;
    case 0x3c:
      FUN_00617e30(DAT_02962938);
      FUN_00621040(0);
      FUN_00620f40(0,0x4000);
      FUN_00621140();
      DAT_02962934 = DAT_02962934 + -1;
      return;
    }
    DAT_02962934 = DAT_02962934 + -1;
  }
  return;
}

