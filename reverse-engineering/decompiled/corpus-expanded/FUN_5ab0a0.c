/* Ghidra pseudocode, not original source.
 * ev_51f4537ed7c57c9a0fa7f304a7a0f3427cc608dfecd65a4b8280241ed2e1f797
 * Entry: 0x5ab0a0; label: FUN_005ab0a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined2 * FUN_005ab0a0(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined2 *puVar1;
  int iVar2;
  
  puVar1 = (undefined2 *)0x0;
  if ((param_3 != 0) &&
     (puVar1 = (undefined2 *)FUN_00517160(param_1,param_2,8), puVar1 != (undefined2 *)0x0)) {
    iVar2 = FUN_00517160(param_1,param_2,param_3 << 4);
    *(int *)(puVar1 + 2) = iVar2;
    if (iVar2 != 0) {
      *puVar1 = (short)param_3;
    }
  }
  return puVar1;
}

