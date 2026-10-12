/* Ghidra pseudocode, not original source.
 * ev_64ab134b4afd9c8d0a163dd8f67d256d98012891aab565beeb69ac94b847fa54
 * Entry: 0x5dafd0; label: FUN_005dafd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005dafd0(int param_1)

{
  FUN_005dad10(param_1,param_1 + 4);
  *(float *)(param_1 + 8) =
       ((float)DAT_00963e18 * 0.0625) / ((float)DAT_00973900 / (float)DAT_0080e694);
  *(float *)(param_1 + 0xc) =
       ((float)DAT_00963e1c * 0.0625) / ((float)DAT_00973904 / (float)DAT_0080e698);
  *(undefined4 *)(param_1 + 0x18) = _DAT_00963e28;
  *(undefined4 *)(param_1 + 0x1c) = _DAT_00963e2c;
  *(undefined4 *)(param_1 + 0x20) = _DAT_00963e30;
  *(undefined4 *)(param_1 + 0x24) = _DAT_00963e34;
  *(undefined4 *)(param_1 + 0x28) = _DAT_00963e38;
  *(undefined4 *)(param_1 + 0x2c) = _DAT_00963e3c;
  *(undefined4 *)(param_1 + 0x30) = _DAT_00963e40;
  *(undefined4 *)(param_1 + 0x34) = _DAT_00963e44;
  *(undefined4 *)(param_1 + 0x38) = _DAT_00963e48;
  *(undefined4 *)(param_1 + 0x3c) = _DAT_00963e4c;
  return;
}

