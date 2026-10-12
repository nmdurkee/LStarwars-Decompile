/* Ghidra pseudocode, not original source.
 * ev_dfc36d2b541ec0d46ba2179b7939a25d003ccbe30d4bab0c10c333595f465d14
 * Entry: 0x655f30; label: FUN_00655f30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00655f30(int param_1,uint param_2)

{
  undefined2 uVar1;
  
  if (param_2 != 0) {
    param_1 = param_1 * 0x330;
    uVar1 = FUN_005d92b0(param_2,param_1 + 400 + DAT_029620a4);
    *(undefined2 *)(param_1 + 0x2f2 + DAT_029620a4) = uVar1;
    *(uint *)(param_1 + 0x2fc + DAT_029620a4) =
         -(uint)(*(short *)(param_1 + 0x2f2 + DAT_029620a4) != -1) & param_2;
    return;
  }
  *(undefined2 *)(param_1 * 0x330 + 0x2f2 + DAT_029620a4) = 0xffff;
  *(undefined4 *)(param_1 * 0x330 + 0x2fc + DAT_029620a4) = 0;
  return;
}

