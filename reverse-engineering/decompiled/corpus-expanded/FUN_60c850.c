/* Ghidra pseudocode, not original source.
 * ev_0c11dca3c01e2e078e91e20b90f08271c2558dc41f56def09ad2bffabccf1687
 * Entry: 0x60c850; label: FUN_0060c850
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

bool FUN_0060c850(uint param_1,char param_2)

{
  uint uVar1;
  void *_Src;
  int in_ECX;
  uint _MaxCount;
  
  if (param_1 == 0xffffffff) {
    FUN_006e67be();
  }
  uVar1 = *(uint *)(in_ECX + 0x18);
  if (uVar1 < param_1) {
    FUN_0060bdd0(param_1,*(undefined4 *)(in_ECX + 0x14));
    return param_1 != 0;
  }
  if ((param_2 != '\0') && (param_1 < 0x10)) {
    _MaxCount = *(uint *)(in_ECX + 0x14);
    if (param_1 < *(uint *)(in_ECX + 0x14)) {
      _MaxCount = param_1;
    }
    if (0xf < uVar1) {
      _Src = *(void **)(in_ECX + 4);
      if (_MaxCount != 0) {
        _memcpy_s((undefined4 *)(in_ECX + 4),0x10,_Src,_MaxCount);
      }
      FUN_006e85b0(_Src);
    }
    *(uint *)(in_ECX + 0x14) = _MaxCount;
    *(undefined4 *)(in_ECX + 0x18) = 0xf;
    *(undefined1 *)(in_ECX + 4 + _MaxCount) = 0;
    return param_1 != 0;
  }
  if (param_1 == 0) {
    *(undefined4 *)(in_ECX + 0x14) = 0;
    if (0xf < uVar1) {
      **(undefined1 **)(in_ECX + 4) = 0;
      return false;
    }
    *(undefined1 *)(in_ECX + 4) = 0;
  }
  return param_1 != 0;
}

