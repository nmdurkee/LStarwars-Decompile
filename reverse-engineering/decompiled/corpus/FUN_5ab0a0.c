/* Ghidra analysis pseudocode, not original source.
 * ev_2c014b146e9258db07d80d50b3912bad4b2773c74b3e67189abd65c219d7972f
 * Entry: 0x5ab0a0; label: FUN_005ab0a0
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

