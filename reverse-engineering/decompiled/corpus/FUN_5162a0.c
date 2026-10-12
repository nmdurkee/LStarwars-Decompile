/* Ghidra analysis pseudocode, not original source.
 * ev_84e2b506f29363daa42df6f934b4c92b1585b3e8a57a6b6866ee0e5470757f5b
 * Entry: 0x5162a0; label: FUN_005162a0
 */

undefined4
FUN_005162a0(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  
  if (((param_3 != 0) && (*(int *)(param_3 + 0xd0) != 0)) && (param_6 != 0)) {
    puVar1 = (uint *)(*(int *)(param_3 + 0xd0) + 0x1fc);
    *puVar1 = *puVar1 | 0x10;
    iVar3 = 0;
    if (0 < param_5) {
      do {
        iVar2 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar3 * 4),"false");
        if (iVar2 == 0) {
          puVar1 = (uint *)(*(int *)(param_3 + 0xd0) + 0x1fc);
          *puVar1 = *puVar1 & 0xffffffef;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < param_5);
    }
  }
  return 1;
}

