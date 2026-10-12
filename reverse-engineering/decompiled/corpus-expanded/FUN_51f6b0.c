/* Ghidra pseudocode, not original source.
 * ev_b2a783233b211c47b682189f4533ad6a7c38bd84c0deaf183226d349bdd9b928
 * Entry: 0x51f6b0; label: FUN_0051f6b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0051f6b0(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = param_1;
  if (*(int *)(param_1 + 0x15c) != *(int *)(param_1 + 0x1d0)) {
    iVar3 = FUN_0051be90(&param_1);
    if (iVar3 != 0) {
      if (param_2 != (undefined4 *)0x0) {
        puVar1 = (undefined4 *)
                 ((uint)*(byte *)((param_1 == 0) + 0x10 + iVar3) * 0x5c + 4 +
                 *(int *)(*(int *)(iVar2 + 0x158) + 0x7c));
        *param_2 = *puVar1;
        param_2[1] = puVar1[1];
        param_2[2] = puVar1[2];
      }
      return 1;
    }
  }
  return 0;
}

