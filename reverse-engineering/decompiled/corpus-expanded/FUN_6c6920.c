/* Ghidra pseudocode, not original source.
 * ev_647b85ee0a7e8e41d889ce710347a98583a3d140d8a364c007ecae69f59044b8
 * Entry: 0x6c6920; label: FUN_006c6920
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_006c6920(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  undefined4 uVar3;
  
  iVar1 = *(int *)(in_ECX + 8);
  do {
    if (iVar1 == 0) {
      return 0;
    }
    if ((*(uint *)(iVar1 + 0x1c) & 0x80000000) == 0) {
      uVar3 = *(undefined4 *)(iVar1 + 0x10);
LAB_006c6978:
      iVar2 = FUN_004f8b10(uVar3,param_1);
      if (iVar2 == 0) {
        return iVar1;
      }
    }
    else {
      if (param_2 == 0) {
        uVar3 = *(undefined4 *)(iVar1 + 0x10);
        goto LAB_006c6978;
      }
      iVar2 = FUN_006c6920(param_1,1);
      if (iVar2 != 0) {
        return iVar2;
      }
    }
    iVar1 = *(int *)(iVar1 + 4);
  } while( true );
}

