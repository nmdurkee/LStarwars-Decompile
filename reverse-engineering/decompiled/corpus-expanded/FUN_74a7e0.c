/* Ghidra pseudocode, not original source.
 * ev_e0447f8e73d2150c5385a8aa294440164da99c01f5f62ba5bd70b4e5b4546b39
 * Entry: 0x74a7e0; label: FUN_0074a7e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0074a7e0(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 unaff_ESI;
  int *piVar3;
  undefined1 local_8 [4];
  int *local_4;
  
  D3DXCreateBuffer(0x80,local_8);
  D3DXCreateEffectCompiler(param_1,param_2,0,0,0,&local_4,0);
  piVar3 = (int *)0x0;
  (**(code **)(*local_4 + 0xec))(local_4,0,local_8,0);
  uVar1 = (**(code **)(*piVar3 + 0x10))();
  uVar2 = (**(code **)(*local_4 + 0xc))(local_4,uVar1);
  FUN_004ef660(unaff_ESI,uVar2);
  (**(code **)(*piVar3 + 8))(piVar3);
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 8))(piVar3);
  }
  return uVar1;
}

