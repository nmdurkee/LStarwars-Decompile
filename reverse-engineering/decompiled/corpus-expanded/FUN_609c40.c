/* Ghidra pseudocode, not original source.
 * ev_deacb65ff86bfd262c36c7125baff66f7c0e4faab911474243066d5360a0fd29
 * Entry: 0x609c40; label: FUN_00609c40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00609c40(int param_1,int param_2)

{
  int iVar1;
  void *_Dst;
  
  if ((param_2 != 0) && (*(int *)(param_1 + 0x20) != 0)) {
    if (*(int *)(param_1 + 0x1c) == 0) {
      FUN_006e5b90(0,0,(int *)(param_1 + 0x1c),0,*(undefined4 *)(param_1 + 0x48));
      if (*(int *)(param_1 + 0x1c) == 0) {
        FUN_005f7490();
      }
    }
    iVar1 = FUN_00602f50(*(undefined4 *)(param_1 + 0x68));
    _memcpy(_Dst,*(void **)(param_1 + 0x20),iVar1 * *(int *)(param_1 + 0x10));
  }
  if (*(int *)(param_1 + 0x1c) != 0) {
    FUN_006e5bc0(*(undefined4 *)(param_1 + 0x48));
  }
  *(undefined4 *)(param_1 + 0x1c) = 0;
  return;
}

