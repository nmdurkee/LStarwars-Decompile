/* Ghidra pseudocode, not original source.
 * ev_8c943698e03161dcf7a1afd17c02789bd1a03bc5c571948a550cbb172219f06a
 * Entry: 0x55b2d0; label: FUN_0055b2d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0055b2d0(int *param_1)

{
  void *_Dst;
  size_t _Size;
  
  _Size = DAT_0093b278 * 0x10;
  _Dst = (void *)(*param_1 + 3U & 0xfffffffc);
  DAT_0093b27c = _Dst;
  *param_1 = (int)((int)_Dst + _Size);
  _memset(_Dst,0,_Size);
  return;
}

