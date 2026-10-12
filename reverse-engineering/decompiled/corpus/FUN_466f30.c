/* Ghidra analysis pseudocode, not original source.
 * ev_7062545ad2ab2af07ec33b13480d196f765b27a757bdc9b0fea79766ea2b2f64
 * Entry: 0x466f30; label: FUN_00466f30
 */

void FUN_00466f30(undefined4 param_1,int *param_2)

{
  undefined2 uVar1;
  uint *puVar2;
  int iVar3;
  
  if (param_2 != (int *)0x0) {
    iVar3 = 0;
    if (*(short *)((int)param_2 + 0xe) != 0) {
      puVar2 = (uint *)(*param_2 + 0xa0);
      do {
        if ((*puVar2 & 0x400) != 0) {
          uVar1 = FUN_0056aa40(param_1,(int)(short)puVar2[-6]);
          *puVar2 = *puVar2 & 0xfffffbff;
          *(undefined2 *)(puVar2 + -6) = uVar1;
        }
        iVar3 = iVar3 + 1;
        puVar2 = puVar2 + 0x29;
      } while (iVar3 < (int)(uint)*(ushort *)((int)param_2 + 0xe));
    }
  }
  return;
}

