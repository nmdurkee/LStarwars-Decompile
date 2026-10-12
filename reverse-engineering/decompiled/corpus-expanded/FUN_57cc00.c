/* Ghidra pseudocode, not original source.
 * ev_608779b64e90f57b93ecbf13df65bed39f2d483d8cb24d2405739ebf49354e95
 * Entry: 0x57cc00; label: FUN_0057cc00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0057cc00(int param_1,undefined4 param_2,int *param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 local_40 [12];
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar2 = 0;
  if ((*(byte *)(param_4 + 0x5c) & 2) == 0) {
    iVar2 = *param_3;
  }
  FUN_00503050(param_4,param_5,local_40,&param_4,0,0,0,0,0);
  if ((*(byte *)(param_1 + 0x88) & 0x80) != 0) {
    FUN_005b5430(local_40,local_40,param_1 + 0x18);
  }
  if (iVar2 != 0) {
    puVar3 = local_40;
    puVar4 = (undefined4 *)(iVar2 + 0xb8);
    for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    *(undefined4 *)(iVar2 + 0x5c) = local_10;
    *(undefined4 *)(iVar2 + 0x60) = local_c;
    *(undefined4 *)(iVar2 + 100) = local_8;
  }
  return;
}

