/* Ghidra pseudocode, not original source.
 * ev_26d1fac8fd457d7aa06190d117e50b4f3cb6f2e0dd1b5e3302fd798cb5ca6742
 * Entry: 0x43c9a0; label: FUN_0043c9a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0043c9a0(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 local_c;
  float local_8;
  undefined4 local_4;
  
  if ((((*(uint *)(param_1 + 0x1f8) & 0x400) == 0) && ((*(byte *)(param_1 + 0x42e) & 1) != 0)) &&
     ((_DAT_007f6738 < *(float *)(param_1 + 0xf10) != (_DAT_007f6738 == *(float *)(param_1 + 0xf10))
      || (((*(char *)(param_1 + 0x288) == '\0' && ((*(byte *)(param_1 + 0x7c5) & 2) == 0)) &&
          (0.0 < _DAT_00876ce4)))))) {
    local_c = *(undefined4 *)(param_2 + 4);
    local_4 = *(undefined4 *)(param_2 + 0xc);
    local_8 = *(float *)(param_1 + 0x1e0) + *(float *)(param_2 + 8);
    iVar1 = FUN_005d6620(&local_c,*(undefined4 *)(param_1 + 0x1e0),&DAT_00806680);
    if (iVar1 != 0) {
      if (param_3 == 0) {
        iVar1 = *(int *)(param_1 + 0x398);
        *(undefined4 *)(iVar1 + 0x5c) = *(undefined4 *)(param_2 + 4);
        *(undefined4 *)(iVar1 + 0x60) = *(undefined4 *)(param_2 + 8);
        *(undefined4 *)(iVar1 + 100) = *(undefined4 *)(param_2 + 0xc);
        iVar1 = *(int *)(param_1 + 0x398);
        *(undefined4 *)(param_1 + 0x98) = *(undefined4 *)(iVar1 + 0x5c);
        *(undefined4 *)(param_1 + 0x9c) = *(undefined4 *)(iVar1 + 0x60);
        *(undefined4 *)(param_1 + 0xa0) = *(undefined4 *)(iVar1 + 100);
        *(undefined4 *)(param_1 + 0x80) = *(undefined4 *)(iVar1 + 0x5c);
        *(undefined4 *)(param_1 + 0x84) = *(undefined4 *)(iVar1 + 0x60);
        *(undefined4 *)(param_1 + 0x88) = *(undefined4 *)(iVar1 + 100);
        _DAT_0093d620 = *(undefined4 *)(param_1 + 0x80);
        DAT_0093d624 = *(undefined4 *)(param_1 + 0x84);
        DAT_0093d628 = *(undefined4 *)(param_1 + 0x88);
        *(undefined4 *)(param_1 + 0x8c) = *(undefined4 *)(param_1 + 0x80);
        *(undefined4 *)(param_1 + 0x90) = *(undefined4 *)(param_1 + 0x84);
        *(undefined4 *)(param_1 + 0x94) = *(undefined4 *)(param_1 + 0x88);
        *(undefined4 *)(param_1 + 0x68) = DAT_0093b0cc;
        *(undefined4 *)(param_1 + 0x6c) = DAT_0093b0d0;
        *(undefined4 *)(param_1 + 0x70) = DAT_0093b0d4;
        FUN_005728a0(param_1);
        FUN_00572660(param_1,0);
        *(undefined4 *)(param_1 + 0x1090) = 0;
        *(undefined1 *)(param_1 + 0x1086) = 0;
        *(undefined1 *)(param_1 + 0x1087) = 0;
        *(undefined1 *)(param_1 + 0x401) = 0;
        if (*(int *)(param_1 + 0xcd0) == 0) {
          FUN_0055e4a0(param_1,0);
          FUN_0055e4e0(param_1 + 0x6c4);
        }
        return 1;
      }
      iVar1 = FUN_004d1780(param_1,(undefined4 *)(param_2 + 4));
      if (iVar1 != 0) {
        *(undefined1 *)(param_1 + 0x1086) = 0;
        *(undefined4 *)(param_1 + 0x1090) = 0;
        *(undefined1 *)(param_1 + 0x1087) = 0;
        *(undefined1 *)(param_1 + 0x401) = 0;
        return 1;
      }
    }
  }
  return 0;
}

