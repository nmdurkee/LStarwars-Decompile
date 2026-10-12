/* Ghidra analysis pseudocode, not original source.
 * ev_5937183d084659f3cd2a7a2e71fd5c7a233dbdbc790437ca60456b8bfcc76022
 * Entry: 0x5487c0; label: FUN_005487c0
 */

void FUN_005487c0(undefined4 param_1,int param_2,float param_3,char param_4,undefined4 param_5,
                 undefined4 param_6)

{
  int iVar1;
  int iVar2;
  
  iVar2 = DAT_00924adc;
  if ((param_4 == '\x01') && (param_3 == 0.0)) {
    if (param_2 != -1) {
      FUN_00681e90(param_2,param_6);
      return;
    }
    FUN_00681f40(param_1,param_6);
    return;
  }
  if (param_3 <= 0.0) {
    (&DAT_00924afa)[DAT_00924adc * 0x10] = 2;
  }
  else {
    (&DAT_00924afa)[DAT_00924adc * 0x10] = 1;
  }
  if (param_2 == -1) {
    param_2 = FUN_00650dc0(param_1);
    iVar2 = DAT_00924adc;
  }
  iVar1 = iVar2 * 0x10;
  *(short *)(&DAT_00924af8 + iVar1) = (short)param_2;
  (&DAT_00924afc)[iVar2 * 4] = param_3;
  (&DAT_00924afb)[iVar1] = param_4;
  *(undefined4 *)(&DAT_00924b00 + iVar1) = param_5;
  *(undefined4 *)(&DAT_00924b04 + iVar1) = param_6;
  DAT_00924adc = iVar2 + 1U & 0x1f;
  return;
}

