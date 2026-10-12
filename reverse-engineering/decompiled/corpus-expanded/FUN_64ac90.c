/* Ghidra pseudocode, not original source.
 * ev_3e786b2ab64c48f97439d141d8ad45f587e334c03ef45226df6d6e53cdeb8069
 * Entry: 0x64ac90; label: FUN_0064ac90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0064ac90(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_1;
  if ((*(uint *)(param_1 + 0x144) & 1) != 0) {
    *(uint *)(param_1 + 0x144) = *(uint *)(param_1 + 0x144) & 0xfffffffe;
    if (((*(uint *)(param_1 + 0x108) & 0x20000) != 0) && (*(int *)(param_1 + 0x1d8) != 0)) {
      FUN_00684400(*(int *)(param_1 + 0x1d8));
    }
    if (*(undefined4 **)(iVar1 + 0x1dc) != (undefined4 *)0x0) {
      FUN_00635750(**(undefined4 **)(iVar1 + 0x1dc));
      **(undefined4 **)(iVar1 + 0x1dc) = 0xffffffff;
    }
    iVar2 = param_2;
    if (*(code **)(iVar1 + 0x1c0) != (code *)0x0) {
      (**(code **)(iVar1 + 0x1c0))(iVar1,param_2);
    }
    if ((iVar2 != 6) && (*(int *)(iVar1 + 500) != -1)) {
      param_1 = 0xffffffff;
      FUN_00690490(&param_1,*(int *)(iVar1 + 500),iVar1 + 0x30,0,0,1,*(undefined4 *)(iVar1 + 0x1fc))
      ;
    }
  }
  return;
}

