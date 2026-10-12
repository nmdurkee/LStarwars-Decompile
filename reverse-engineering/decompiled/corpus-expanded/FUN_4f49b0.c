/* Ghidra pseudocode, not original source.
 * ev_621a163f2f4eeffab67db0a5a6d80d4261cbfd10193b5f3a01bc1d3544017af8
 * Entry: 0x4f49b0; label: FUN_004f49b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_004f49b0(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_1;
  if (((&DAT_0297e044)[iVar2 * 3] == -1) &&
     ((DAT_0091ef2c == 0 || ((&DAT_00917000)[iVar2 * 0x84] == '\0')))) {
    param_1[0x20] = param_1[0x20] & 0xfffffffb;
    param_1[0x1c] = 0;
    param_1[0x1e] = 0;
    param_1[0x1f] = 0;
    param_1[0x1d] = 0;
    return 0;
  }
  if (DAT_0091ef2c == 0) {
    iVar2 = (&DAT_0297e044)[iVar2 * 3];
  }
  iVar1 = iVar2 * 0x84;
  *(undefined1 *)((int)param_1 + 0x92) = (&DAT_00917008)[iVar1];
  *(undefined1 *)((int)param_1 + 0x93) = (&DAT_00917009)[iVar1];
  *(undefined1 *)(param_1 + 0x24) = (&DAT_0091700a)[iVar1];
  *(undefined1 *)((int)param_1 + 0x91) = (&DAT_0091700b)[iVar1];
  *(undefined *)(param_1 + 0x27) = (&DAT_0091700c)[iVar1];
  *(undefined *)((int)param_1 + 0x9e) = (&DAT_0091700d)[iVar1];
  *(undefined *)((int)param_1 + 0x9d) = (&DAT_0091700e)[iVar1];
  *(undefined *)((int)param_1 + 0x9f) = (&DAT_0091700f)[iVar1];
  param_1[0x1c] = (&DAT_00917010)[iVar2 * 0x21];
  param_1[0x1e] = (&DAT_00917014)[iVar2 * 0x21];
  param_1[0x1f] = *(int *)(&DAT_00917018 + iVar1);
  param_1[0x1d] = *(int *)(&DAT_0091701c + iVar1);
  param_1[0x20] = param_1[0x20] ^ (*(int *)(&DAT_00917020 + iVar1) * 2 ^ param_1[0x20]) & 2U;
  *(undefined1 *)(param_1 + 0x22) = *(undefined1 *)(&DAT_00917034 + iVar2 * 0x21);
  param_1[4] = *(int *)(&DAT_00917024 + iVar1);
  param_1[5] = *(int *)(&DAT_00917028 + iVar1);
  param_1[6] = *(int *)(&DAT_0091702c + iVar1);
  param_1[7] = *(int *)(&DAT_00917030 + iVar1);
  param_1[8] = *(int *)(&DAT_00917038 + iVar1);
  param_1[9] = *(int *)(&DAT_0091703c + iVar1);
  param_1[10] = *(int *)(&DAT_00917040 + iVar1);
  param_1[0xb] = *(int *)(&DAT_00917044 + iVar1);
  param_1[0xc] = *(int *)(&DAT_00917048 + iVar1);
  param_1[0xd] = *(int *)(&DAT_0091704c + iVar1);
  param_1[0x12] = *(int *)(&DAT_00917050 + iVar1);
  param_1[0x13] = *(int *)(&DAT_00917054 + iVar1);
  param_1[0xe] = *(int *)(&DAT_00917058 + iVar1);
  param_1[0xf] = *(int *)(&DAT_0091705c + iVar1);
  param_1[0x10] = *(int *)(&DAT_00917060 + iVar1);
  param_1[0x11] = *(int *)(&DAT_00917064 + iVar1);
  *(undefined *)((int)param_1 + 0x95) = (&DAT_00917078)[iVar1];
  *(undefined *)(param_1 + 0x25) = (&DAT_00917079)[iVar1];
  *(undefined *)((int)param_1 + 0x96) = (&DAT_0091707a)[iVar1];
  *(undefined *)((int)param_1 + 0x97) = (&DAT_0091707b)[iVar1];
  *(undefined *)(param_1 + 0x28) = (&DAT_00917082)[iVar1];
  *(undefined *)((int)param_1 + 0xa1) = (&DAT_00917083)[iVar1];
  param_1[0x20] = param_1[0x20] ^ ((uint)(byte)(&DAT_00917000)[iVar1] * 4 ^ param_1[0x20]) & 4;
  return (param_1[0x20] << 0x1d) >> 0x1f;
}

