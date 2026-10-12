/* Ghidra pseudocode, not original source.
 * ev_e3b3033091aeb82eb30298db917b9f24103ba523fce1c25e6a380c5931a7a891
 * Entry: 0x5647e0; label: FUN_005647e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005647e0(int param_1)

{
  float fVar1;
  int iVar2;
  float10 fVar3;
  
  if (DAT_0095073c != 0) {
    _DAT_00950724 = 0.0;
    _DAT_00950728 = 0.0;
    _DAT_0095072c = 0.0;
    _DAT_00950730 = 0.0;
    _DAT_00950734 = 0.0;
    _DAT_00802e1c = 0.0;
    return;
  }
  if (_DAT_00950738 <= 0.0) {
    if ((((_DAT_00950710 == _DAT_00950724) && (_DAT_00950714 == _DAT_00950728)) &&
        (_DAT_00950718 == _DAT_0095072c)) &&
       (((_DAT_0095071c == _DAT_00950730 && (_DAT_00950720 == _DAT_00950734)) &&
        (_DAT_00802e18 == _DAT_00802e1c)))) {
      iVar2 = FUN_0054fa60();
      _DAT_00950738 = (float)iVar2 * 1.5259022e-05 * 2.5 + 2.5;
      return;
    }
    fVar1 = _DAT_00925018 * 10.0;
    fVar3 = (float10)FUN_0054fad0(_DAT_00950724,_DAT_00950710,fVar1);
    _DAT_00950724 = (float)fVar3;
    fVar3 = (float10)FUN_0054fad0(_DAT_00950728,_DAT_00950714,fVar1);
    _DAT_00950728 = (float)fVar3;
    fVar3 = (float10)FUN_0054fad0(_DAT_0095072c,_DAT_00950718,fVar1);
    _DAT_0095072c = (float)fVar3;
    fVar3 = (float10)FUN_0054fad0(_DAT_00950730,_DAT_0095071c,fVar1);
    _DAT_00950730 = (float)fVar3;
    fVar3 = (float10)FUN_0054fad0(_DAT_00950734,_DAT_00950720,fVar1);
    _DAT_00950734 = (float)fVar3;
    fVar3 = (float10)FUN_0054fad0(_DAT_00802e1c,_DAT_00802e18,fVar1);
    _DAT_00802e1c = (float)fVar3;
    return;
  }
  _DAT_00950738 = _DAT_00950738 - _DAT_00925018;
  if (0.0 < _DAT_00950738) {
    return;
  }
  if (param_1 != 0) {
    _DAT_00950718 = 0.0;
    _DAT_00950714 = 0.0;
    _DAT_00950710 = 0.0;
    _DAT_00802e18 = 0.0;
    _DAT_00950720 = 0.0;
    _DAT_0095071c = 0.0;
    return;
  }
  FUN_00564750();
  return;
}

