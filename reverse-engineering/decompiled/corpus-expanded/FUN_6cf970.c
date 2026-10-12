/* Ghidra pseudocode, not original source.
 * ev_b393d28c9e9a0ec683edd3b274f1828e861e17aa87a3660c9a4e9e0f17cff856
 * Entry: 0x6cf970; label: FUN_006cf970
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006cf970(undefined4 param_1,int param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = (undefined4 *)FUN_00633440(0x10,1);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = &PTR_FUN_0076b630;
    puVar1[2] = param_2;
    puVar1[3] = param_3;
    uVar2 = FUN_00626250(puVar1,&DAT_0081f9a0,FUN_006cf8e0,0,0,0,*(undefined4 *)(param_2 + 0x10),0);
    puVar1[1] = uVar2;
    FUN_00618e10(param_1,uVar2);
  }
  return;
}

