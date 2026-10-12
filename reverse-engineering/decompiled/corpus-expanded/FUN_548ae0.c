/* Ghidra pseudocode, not original source.
 * ev_f0f87d832dbe8e7fa4eaa2c5681d260c3f1d1a42269eaf7f506f4d6846a5d20b
 * Entry: 0x548ae0; label: FUN_00548ae0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00548ae0(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = DAT_00924aec;
  _DAT_008020dc = DAT_008020d8;
  DAT_00924aec = 0;
  if ((DAT_02962034 == 0) && (DAT_02962038 == 0)) {
    if (DAT_00924df4 == (code *)0x0) {
      DAT_00924aec = 0;
    }
    else {
      DAT_00924aec = (*DAT_00924df4)();
    }
    if (param_2 == 0) {
      _DAT_00924dd4 = 0;
      DAT_00924dd0 = DAT_00924af4;
    }
    else if (DAT_00924aec == iVar1) {
      return;
    }
    FUN_00694240(1,*(undefined4 *)(param_1 + 0x118 + DAT_00924aec * 4));
    FUN_00694240(2,*(undefined4 *)(param_1 + 0x120 + DAT_00924aec * 4));
    FUN_00694240(0x20,*(undefined4 *)(param_1 + 0x128 + DAT_00924aec * 4));
    if (*(char *)(param_3 + 6) != '\0') {
      if (DAT_00924dd0 == 0) {
        iVar1 = FUN_00694320(1,0);
        if (iVar1 != -1) goto LAB_00548be0;
        iVar1 = FUN_00694320(2,0);
        if (iVar1 != -1) {
          FUN_00696a30(2);
          return;
        }
      }
      else {
        iVar1 = FUN_00694320(2,0);
        if (iVar1 != -1) {
          FUN_00696a30(2);
          return;
        }
        iVar1 = FUN_00694320(1,0);
        if (iVar1 != -1) {
LAB_00548be0:
          FUN_00696a30(1);
          return;
        }
      }
    }
    FUN_00696a30(0x20);
  }
  return;
}

