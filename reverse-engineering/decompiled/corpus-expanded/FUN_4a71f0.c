/* Ghidra pseudocode, not original source.
 * ev_2e86f2171d5c14e65a9d827277689f6eb238c30686d251b2df2a036861678988
 * Entry: 0x4a71f0; label: FUN_004a71f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004a71f0(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_4;
  
  if (((((*(byte *)(param_1 + 0x1fc) & 0x80) != 0) && (*(char *)(param_1 + 0x7b5) == -1)) &&
      (*(int *)(param_1 + 0x1040) == 0)) &&
     (iVar1 = FUN_0040a2a0(param_1,param_1 + 0x80,_DAT_007f1050 * 0.9), iVar1 != 0)) {
    *(uint *)(param_1 + 0xe24) = *(uint *)(param_1 + 0xe24) | 0x10;
    if (param_2 == 0) {
      *(int *)(param_1 + 0xd18) = iVar1;
      *(undefined1 *)(param_1 + 0xe2d) = 2;
    }
    else {
      uVar2 = FUN_00408880(param_1,iVar1,1);
      *(undefined4 *)(param_1 + 0x1040) = uVar2;
      FUN_00576960(0x28e);
    }
  }
  FUN_004a4ff0(0xe3);
  if ((((*(byte *)(param_1 + 0x1fc) & 0x80) != 0) && (*(char *)(param_1 + 0xe2d) != '\0')) &&
     ((*(int *)(param_1 + 0xd18) != 0 &&
      ((0.0 < *(float *)(param_1 + 0xd80) &&
       (iVar1 = FUN_00560fa0(&DAT_00759770,*(int *)(param_1 + 0xd18) + 0x80,
                             _DAT_007fc090 * DAT_00950f60,0,0,0xff,0,0,0x10c7,0), iVar1 != 0)))))) {
    *(undefined1 *)(iVar1 + 0xfe) = 5;
    *(code **)(iVar1 + 0x10c) = FUN_004d3220;
    local_4 = (undefined1)(int)ROUND((*(float *)(param_1 + 0xd80) / _DAT_007fc074) * 128.0);
    *(undefined1 *)(iVar1 + 0xf7) = local_4;
    return;
  }
  return;
}

