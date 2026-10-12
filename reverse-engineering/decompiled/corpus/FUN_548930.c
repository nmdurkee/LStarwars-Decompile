/* Ghidra analysis pseudocode, not original source.
 * ev_5937183d084659f3cd2a7a2e71fd5c7a233dbdbc790437ca60456b8bfcc76022
 * Entry: 0x548930; label: FUN_00548930
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00548930(undefined4 param_1,int param_2)

{
  int iVar1;
  
  *(undefined1 *)(param_2 + 3) = 8;
  *(undefined1 *)(param_2 + 4) = 6;
  if ((DAT_00924dcc == (code *)0x0) || (iVar1 = (*DAT_00924dcc)(param_1), iVar1 == 0)) {
    if (DAT_00951288 == 0) {
      _DAT_00810d9c = 0x40000000;
      _DAT_00810d98 = 0x41700000;
    }
    else {
      _DAT_00810d9c = 0x41200000;
      _DAT_00810d98 = 0x42a00000;
    }
  }
  FUN_00547b20(param_2);
  FUN_00547ab0(param_2);
  return;
}

