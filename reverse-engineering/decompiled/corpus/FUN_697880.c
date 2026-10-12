/* Ghidra analysis pseudocode, not original source.
 * ev_7a6f44793a1ae116413d84873b30ec9fe28028ad0afd3b3275dd7a03cd0119e5
 * Entry: 0x697880; label: FUN_00697880
 */

void FUN_00697880(int param_1,undefined4 *param_2,int param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int in_ECX;
  bool bVar4;
  
  puVar2 = (undefined4 *)(param_1 * 0x34 + 0xc + in_ECX);
  bVar4 = param_3 == 0;
  puVar1 = puVar2 + 1;
  if (puVar2[1] == 0) {
    iVar3 = (*(code *)**(undefined4 **)*puVar2)((undefined4 *)*puVar2,&DAT_0078493c,puVar1);
    if (iVar3 < 0) {
      return;
    }
    (**(code **)(*(int *)*puVar1 + 0x40))((int *)*puVar1,0x4e6e6b28,bVar4);
    (**(code **)(*(int *)*puVar1 + 0x44))((int *)*puVar1,0x4e6e6b28,bVar4);
    (**(code **)(*(int *)*puVar1 + 0x48))((int *)*puVar1,1,bVar4);
  }
  (**(code **)(*(int *)*puVar1 + 0x4c))((int *)*puVar1,*param_2,param_2[1],param_2[2],bVar4);
  return;
}

