/* Ghidra analysis pseudocode, not original source.
 * ev_84e2b506f29363daa42df6f934b4c92b1585b3e8a57a6b6866ee0e5470757f5b
 * Entry: 0x516520; label: FUN_00516520
 */

undefined4
FUN_00516520(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  int iVar2;
  
  if ((param_3 != 0) && (param_6 != 0)) {
    *(uint *)(param_3 + 0x1e8) = *(uint *)(param_3 + 0x1e8) | 0x20000;
    iVar2 = 0;
    if (0 < param_5) {
      do {
        iVar1 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar2 * 4),"false");
        if (iVar1 == 0) {
          *(uint *)(param_3 + 0x1e8) = *(uint *)(param_3 + 0x1e8) & 0xfffdffff;
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < param_5);
    }
  }
  return 1;
}

