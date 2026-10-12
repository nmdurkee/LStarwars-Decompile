/* Ghidra pseudocode, not original source.
 * ev_d0ee5b940732101f19a6f5ed1cc5d22784960ef3dbbb4fefd6b0cd8a13c6d459
 * Entry: 0x73ea95; label: _StringCchCopyW@12
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    _StringCchCopyW@12
   
   Library: Visual Studio 2005 Release */

undefined4 _StringCchCopyW_12(undefined4 param_1,uint param_2)

{
  undefined4 uVar1;
  
  if (0x7fffffff < param_2) {
    return 0x80070057;
  }
  uVar1 = _StringCopyWorkerW_12();
  return uVar1;
}

