/* Ghidra pseudocode, not original source.
 * ev_b2a783233b211c47b682189f4533ad6a7c38bd84c0deaf183226d349bdd9b928
 * Entry: 0x520550; label: FUN_00520550
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00520550(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  undefined4 *puVar2;
  
  *(uint *)(DAT_009238e4 + 0x43828) = *(uint *)(DAT_009238e4 + 0x43828) | 2;
  *(undefined4 *)(DAT_009238e4 + 100) = param_1;
  *(undefined4 *)(DAT_009238e4 + 8) = param_3;
  *(undefined4 *)(DAT_009238e4 + 0xc) = param_4;
  *(undefined4 *)(DAT_009238e4 + 0x4382c) = param_5;
  *(undefined4 *)(DAT_009238e4 + 0x43830) = param_6;
  *(undefined4 *)(DAT_009238e4 + 0x43834) = param_7;
  if (param_2 != 0) {
    FUN_00620f10(param_2);
  }
  iVar1 = 0;
  if (0 < DAT_009220ec) {
    puVar2 = &DAT_00921f8c;
    do {
      if ((code *)*puVar2 != (code *)0x0) {
        (*(code *)*puVar2)();
      }
      iVar1 = iVar1 + 1;
      puVar2 = puVar2 + 0xc;
    } while (iVar1 < DAT_009220ec);
  }
  DAT_00921f50 = DAT_00921f50 | 0x10;
  return;
}

