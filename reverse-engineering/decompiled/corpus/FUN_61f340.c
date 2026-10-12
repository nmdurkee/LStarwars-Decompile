/* Ghidra analysis pseudocode, not original source.
 * ev_9121b524f6182e73d65d2cf5b7796f5032c40ac2ecc24e842002b0e6ddc347ec
 * Entry: 0x61f340; label: FUN_0061f340
 */

void FUN_0061f340(undefined4 param_1,float param_2,undefined4 param_3,float param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  int iVar1;
  int iVar2;
  undefined4 in_EDX;
  
  iVar2 = DAT_02910ca4;
  if ((DAT_02910ca4 < 0x40) && (DAT_02912e8c == 0)) {
    *(undefined4 *)(&DAT_02912138 + DAT_02910ca4 * 0x24) = param_1;
    iVar1 = DAT_02910ca4 * 0x24;
    DAT_02910ca4 = DAT_02910ca4 + 1;
    *(float *)(&DAT_0291213c + iVar1) = param_2 * 0.5;
    *(undefined4 *)(&DAT_02912140 + iVar1) = param_3;
    *(float *)(&DAT_02912144 + iVar1) = param_4 * 0.5;
    (&DAT_02912148)[iVar2 * 9] = in_EDX;
    (&DAT_0291214c)[iVar2 * 9] = param_5;
    *(undefined4 *)(&DAT_02912150 + iVar1) = param_6;
    *(undefined4 *)(&DAT_02912154 + iVar1) = param_7;
    *(undefined4 *)(&DAT_02912158 + iVar1) = param_8;
  }
  return;
}

