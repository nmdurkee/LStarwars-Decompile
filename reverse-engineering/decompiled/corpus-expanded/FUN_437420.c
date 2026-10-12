/* Ghidra pseudocode, not original source.
 * ev_a581b26cc49c1240ca9fc8201471236b1c0a2571dfff42173a4e3442f2e0fd27
 * Entry: 0x437420; label: FUN_00437420
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00437420(int param_1)

{
  uint uVar1;
  int iVar2;
  int _Val;
  size_t _Size;
  
  FUN_0062c560(*(undefined4 *)(PTR_DAT_00802c54 + 0x134),0x6a,param_1 + 0x30);
  if (*(float *)(param_1 + 0x20c) != -1.0) {
    iVar2 = FUN_006e6b90();
    if (((*(int *)(&DAT_008766b4 + iVar2 * 0x34) != 0) &&
        (uVar1 = *(uint *)(*(int *)(&DAT_008766b4 + iVar2 * 0x34) + 0x1fc), (uVar1 & 1) != 0)) &&
       ((uVar1 & 0x1000) != 0)) {
      iVar2 = FUN_006e6b90();
      *(uint *)(*(int *)(&DAT_008766b4 + iVar2 * 0x34) + 0xef0) =
           *(uint *)(*(int *)(&DAT_008766b4 + iVar2 * 0x34) + 0xef0) & 0xffbfffff;
      iVar2 = FUN_006e6b90(0xffffffff,0xffffffff,1,0,0,0);
      FUN_00437770(*(undefined4 *)(&DAT_008766b4 + iVar2 * 0x34));
      iVar2 = FUN_006e6b90(2,0);
      FUN_004364e0(*(undefined4 *)(&DAT_008766b4 + iVar2 * 0x34));
    }
    _Size = 0x34;
    _Val = 0;
    iVar2 = FUN_006e6b90();
    _memset(&DAT_00876690 + iVar2 * 0x34,_Val,_Size);
  }
  return;
}

