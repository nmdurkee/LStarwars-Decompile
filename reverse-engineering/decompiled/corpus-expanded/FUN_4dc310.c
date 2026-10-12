/* Ghidra pseudocode, not original source.
 * ev_8ce8f2cf434fcaf80bd354ce8b1c39ad0b90beb929885cf3a95e877f90223845
 * Entry: 0x4dc310; label: FUN_004dc310
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004dc310(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  float *pfVar3;
  int *piVar4;
  undefined4 *puVar5;
  
  if ((DAT_00882418 != 0) && (DAT_0088241c != 0)) {
    _DAT_008824a0 = _DAT_008824a0 + _DAT_00925018;
    if ((_DAT_008824aa & 1) == 0) {
      iVar2 = *(int *)(DAT_0088241c + 8);
      puVar5 = &DAT_008824ac;
      piVar4 = &DAT_0093d7f0;
      do {
        if ((*piVar4 != 0) &&
           (iVar1 = FUN_00551170(iVar2,iVar2 + 0xc,*piVar4 + 0x5c,puVar5,0,0), iVar1 != 0)) {
          _DAT_008824aa = _DAT_008824aa | 1;
          DAT_008824a7 = DAT_008824a7 + '\x01';
          break;
        }
        piVar4 = piVar4 + 1;
        puVar5 = puVar5 + 3;
      } while ((int)piVar4 < 0x93d7f8);
    }
    else {
      iVar2 = *(int *)(DAT_00882418 + 8);
      pfVar3 = (float *)&DAT_008824ac;
      piVar4 = &DAT_0093d7f0;
      do {
        if ((((*piVar4 != 0) && (*pfVar3 != -1.0)) && (pfVar3[1] != -1.0)) &&
           ((pfVar3[2] != -1.0 &&
            (iVar1 = FUN_00551170(iVar2,iVar2 + 0xc,*piVar4 + 0x5c,pfVar3,0,0), iVar1 != 0)))) {
          _DAT_008824aa = _DAT_008824aa & 0xfffe;
          _DAT_008824a0 = 0.0;
          DAT_008824a7 = DAT_008824a7 + '\x01';
          DAT_008824a6 = DAT_008824a6 + '\x01';
          if (DAT_008824a6 == '\x03') {
            _DAT_008824aa = _DAT_008824aa | 8;
            FUN_0048f990(param_1);
            FUN_0057a620(param_1,"ep1_podsprint_sebulba",1);
          }
          else if ('\x03' < DAT_008824a6) {
            if (DAT_0093b2a4 == 0) {
              iVar2 = FUN_0057cd30(0,*(undefined4 *)(PTR_DAT_00802c54 + 0x2ab0),"Ep1_Podrace_Outro1"
                                   ,1);
              if ((iVar2 == 0) &&
                 (iVar2 = FUN_0057cd30(0,*(undefined4 *)(PTR_DAT_00802c54 + 0x2ab0),
                                       "Ep1_Podsprint_Outro1",1), iVar2 == 0)) {
                FUN_0057a5b0(param_1);
              }
            }
            else {
              FUN_0057a5b0(param_1);
            }
          }
          break;
        }
        piVar4 = piVar4 + 1;
        pfVar3 = pfVar3 + 3;
      } while ((int)piVar4 < 0x93d7f8);
    }
  }
  if (DAT_0093d7f0 != 0) {
    DAT_008824ac = *(undefined4 *)(DAT_0093d7f0 + 0x5c);
    DAT_008824b0 = *(undefined4 *)(DAT_0093d7f0 + 0x60);
    DAT_008824b4 = *(undefined4 *)(DAT_0093d7f0 + 100);
  }
  if (DAT_0093d7f4 != 0) {
    DAT_008824b8 = *(undefined4 *)(DAT_0093d7f4 + 0x5c);
    DAT_008824bc = *(undefined4 *)(DAT_0093d7f4 + 0x60);
    DAT_008824c0 = *(undefined4 *)(DAT_0093d7f4 + 100);
  }
  *(float *)(DAT_00882480 + 0x28) = (float)(int)DAT_008824a6;
  return;
}

