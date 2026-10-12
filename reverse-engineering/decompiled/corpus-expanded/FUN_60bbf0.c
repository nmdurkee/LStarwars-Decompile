/* Ghidra pseudocode, not original source.
 * ev_8d558f2b7d37f7c2d88d0d36eae1cf7a4b5788ac1ea6cb26aea78645de7b2f49
 * Entry: 0x60bbf0; label: FUN_0060bbf0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0060bbf0(char param_1,rsize_t param_2)

{
  void *_Src;
  int in_ECX;
  
  if ((param_1 != '\0') && (0xf < *(uint *)(in_ECX + 0x18))) {
    _Src = *(void **)(in_ECX + 4);
    if (param_2 != 0) {
      _memcpy_s((undefined4 *)(in_ECX + 4),0x10,_Src,param_2);
    }
    FUN_006e85b0(_Src);
  }
  *(rsize_t *)(in_ECX + 0x14) = param_2;
  *(undefined4 *)(in_ECX + 0x18) = 0xf;
  *(undefined1 *)(in_ECX + 4 + param_2) = 0;
  return;
}

