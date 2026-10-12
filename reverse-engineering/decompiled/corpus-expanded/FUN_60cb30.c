/* Ghidra pseudocode, not original source.
 * ev_0c11dca3c01e2e078e91e20b90f08271c2558dc41f56def09ad2bffabccf1687
 * Entry: 0x60cb30; label: FUN_0060cb30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0060cb30(int param_1,uint param_2,uint param_3)

{
  undefined4 *_Dst;
  int in_ECX;
  undefined4 *puVar1;
  uint _MaxCount;
  
  if (*(uint *)(param_1 + 0x14) < param_2) {
    FUN_006e67fd();
  }
  _MaxCount = *(int *)(param_1 + 0x14) - param_2;
  if (param_3 < _MaxCount) {
    _MaxCount = param_3;
  }
  if (in_ECX != param_1) {
    if (_MaxCount == 0xffffffff) {
      FUN_006e67be();
    }
    if (*(uint *)(in_ECX + 0x18) < _MaxCount) {
      FUN_0060bdd0(_MaxCount,*(undefined4 *)(in_ECX + 0x14));
    }
    else if (_MaxCount == 0) {
      *(undefined4 *)(in_ECX + 0x14) = 0;
      if (*(uint *)(in_ECX + 0x18) < 0x10) {
        *(undefined1 *)(in_ECX + 4) = 0;
        return;
      }
      **(undefined1 **)(in_ECX + 4) = 0;
      return;
    }
    if (_MaxCount != 0) {
      if (*(uint *)(param_1 + 0x18) < 0x10) {
        param_1 = param_1 + 4;
      }
      else {
        param_1 = *(int *)(param_1 + 4);
      }
      puVar1 = (undefined4 *)(in_ECX + 4);
      _Dst = puVar1;
      if (0xf < *(uint *)(in_ECX + 0x18)) {
        _Dst = (undefined4 *)*puVar1;
      }
      _memcpy_s(_Dst,*(uint *)(in_ECX + 0x18),(void *)(param_1 + param_2),_MaxCount);
      *(uint *)(in_ECX + 0x14) = _MaxCount;
      if (0xf < *(uint *)(in_ECX + 0x18)) {
        puVar1 = (undefined4 *)*puVar1;
      }
      *(undefined1 *)((int)puVar1 + _MaxCount) = 0;
    }
    return;
  }
  FUN_0060bcc0(_MaxCount + param_2,0xffffffff);
  FUN_0060bcc0(0,param_2);
  return;
}

