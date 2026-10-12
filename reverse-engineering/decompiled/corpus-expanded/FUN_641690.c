/* Ghidra pseudocode, not original source.
 * ev_df72e9ec6d097d98265581ff35a2e461cddfe69d3931fceba3802c9eedcc8d52
 * Entry: 0x641690; label: FUN_00641690
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_00641690(undefined4 param_1)

{
  int *piVar1;
  int unaff_EDI;
  
  if (DAT_0291396c == 0) {
    DAT_0291396c = FUN_004eef40(0x564,"d:\\projects\\legosagapc\\gameapi.saga\\rtl\\rtl.c",0x13e4);
    FUN_006354a0(DAT_0291396c);
  }
  if (DAT_02913954 == 0) {
    if ((*(uint *)(unaff_EDI + 0x70) & 0x100) == 0) {
      FUN_00620e70();
    }
    FUN_00620fa0(&DAT_029134a4,&DAT_029134fc,&DAT_02913694);
    if ((*(byte *)(unaff_EDI + 0x78) & 0x80) != 0) {
      FUN_00641470();
      DAT_02913954 = DAT_02913958;
    }
    if ((*(uint *)(unaff_EDI + 0x70) & 0x100) != 0) {
      if ((DAT_0291396c == 0) || (*(int *)(DAT_0291396c + 0x554) == -1)) {
        FUN_0063c1b0(0xbf800000,DAT_0291396c);
      }
      else {
        if ((*(byte *)(unaff_EDI + 0x78) & 8) != 0) {
          do {
            *(int *)(DAT_0291396c + 0x554) = *(int *)(DAT_0291396c + 0x554) + 1;
            if (*(int *)(DAT_0291396c + 0x554) == 0x20) {
              *(undefined4 *)(DAT_0291396c + 0x554) = 0;
            }
          } while (*(int *)(DAT_0291396c + 0xd0 + *(int *)(DAT_0291396c + 0x554) * 0x24) == 0);
        }
        if ((*(byte *)(unaff_EDI + 0x78) & 2) != 0) {
          do {
            *(int *)(DAT_0291396c + 0x554) = *(int *)(DAT_0291396c + 0x554) + -1;
            if (*(int *)(DAT_0291396c + 0x554) == -1) {
              *(undefined4 *)(DAT_0291396c + 0x554) = 0x1f;
            }
          } while (*(int *)(DAT_0291396c + 0xd0 + *(int *)(DAT_0291396c + 0x554) * 0x24) == 0);
        }
      }
      if ((DAT_0291396c != 0) && (*(int *)(DAT_0291396c + 0x554) != -1)) {
        FUN_00620f10(DAT_0291396c + 0xd4 + *(int *)(DAT_0291396c + 0x554) * 0x24);
        piVar1 = (int *)(DAT_0291396c + 0x554);
        *(undefined4 *)(DAT_0291396c + 0x558) =
             *(undefined4 *)(DAT_0291396c + 0xec + *(int *)(DAT_0291396c + 0x554) * 0x24);
        *(undefined4 *)(DAT_0291396c + 0x55c) =
             *(undefined4 *)(DAT_0291396c + 0xf0 + *piVar1 * 0x24);
      }
    }
    FUN_00620fa0(&DAT_029134a4,&DAT_029134fc,&DAT_02913694);
    if ((*(uint *)(unaff_EDI + 0x78) & 0x4000) != 0) {
      DAT_0291397c = 0;
    }
    if ((*(uint *)(unaff_EDI + 0x78) & 0x40) != 0) {
      FUN_00639b50(&DAT_029134a4);
    }
    if ((((*(byte *)(unaff_EDI + 0x70) & 0x20) != 0) && (DAT_0291396c != 0)) &&
       (*(int *)(DAT_0291396c + 0x554) != -1)) {
      FUN_00639c80(*(int *)(DAT_0291396c + 0x554),&DAT_029134a4);
    }
    if ((((*(byte *)(unaff_EDI + 0x78) & 0x10) != 0) && (DAT_0291396c != 0)) &&
       (*(int *)(DAT_0291396c + 0x554) != -1)) {
      FUN_00639c30(*(int *)(DAT_0291396c + 0x554));
    }
  }
  else {
    FUN_0062a400(DAT_02913954,param_1);
  }
  FUN_0063c1b0(0xbf800000,DAT_0291396c);
  return *(uint *)(unaff_EDI + 0x78) >> 0xb & 1;
}

