/* Ghidra pseudocode, not original source.
 * ev_3ac53ec2c8a91968fde67182539679734e70c7e49df6a3287feb2aec240cddbe
 * Entry: 0x4278c0; label: FUN_004278c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004278c0(int param_1)

{
  int iVar1;
  float local_c;
  float local_8;
  float local_4;
  
  if ((PTR_DAT_00802c54 != (undefined *)0x0) && (*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b104)
     ) {
    return 0;
  }
  if (((((DAT_0093d810 != 0) && (DAT_0093b2a4 != 0)) && (1 < DAT_007f3964)) &&
      (((DAT_00951288 == 0 && ((DAT_0093b324 != 0 || (DAT_007f3968 != 0)))) &&
       (*(int *)(param_1 + 0xcd0) == 0)))) &&
     ((((*(uint *)(PTR_PTR_007fb0e4 + *(char *)(param_1 + 0x7b5) * 0x10 + 8) & 0x8000) == 0 &&
       (*(char *)(param_1 + 0x7b5) != '+')) &&
      ((*(char *)(param_1 + 0x288) == '\0' && ((*(byte *)(param_1 + 0x7c5) & 2) == 0)))))) {
    local_c = *(float *)(DAT_0093d810 + 0x1b4);
    local_8 = *(float *)(DAT_0093d810 + 0x1b8);
    local_4 = *(float *)(DAT_0093d810 + 0x1bc);
    if (((*(float *)(DAT_0093d810 + 0x5c) == local_c) &&
        (*(float *)(DAT_0093d810 + 0x60) == local_8)) && (*(float *)(DAT_0093d810 + 100) == local_4)
       ) {
      local_4 = local_4 + 0.01;
    }
    iVar1 = FUN_005d6620(&local_c,*(undefined4 *)(param_1 + 0x1e0),&DAT_00806680);
    if (iVar1 == 0) {
      FUN_0041af70(param_1);
      FUN_0055e4a0(param_1,1);
      FUN_0055e4e0(param_1 + 0x6c4);
      *(float *)(param_1 + 0x8c) = local_c;
      *(float *)(param_1 + 0x5c) = local_c;
      *(float *)(param_1 + 0x90) = local_8;
      *(float *)(param_1 + 0x60) = local_8;
      *(float *)(param_1 + 0x94) = local_4;
      *(float *)(param_1 + 100) = local_4;
      *(undefined4 *)(param_1 + 0x68) = DAT_0093b0cc;
      *(undefined4 *)(param_1 + 0x6c) = DAT_0093b0d0;
      *(undefined4 *)(param_1 + 0x70) = DAT_0093b0d4;
      *(undefined2 *)(param_1 + 0x27a) = *(undefined2 *)(DAT_0093d810 + 0x27a);
      FUN_0041af70(param_1);
      *(undefined4 *)(param_1 + 0x1d8) = 0;
      FUN_005728a0(param_1);
      FUN_00572660(param_1,1);
      FUN_0055d2b0(param_1);
      FUN_0062c560(*(undefined4 *)(PTR_DAT_00802c54 + 0x134),0x5c,param_1 + 0x80);
      return 1;
    }
  }
  return 0;
}

