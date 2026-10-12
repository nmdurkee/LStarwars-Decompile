/* Ghidra pseudocode, not original source.
 * ev_01c84f1d9d20bf940b93d5cccd5d039a55498943f529f614c2585109312f1f15
 * Entry: 0x5769d0; label: FUN_005769d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005769d0(float param_1)

{
  short sVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  short *psVar5;
  float10 fVar6;
  
  bVar2 = true;
  iVar3 = FUN_0055f450();
  if (DAT_009514b4 != (short *)0x0) {
    if ((((((DAT_00803984 == 0) || (DAT_00951be0 != 0)) || (DAT_00855de0 == 1)) ||
         ((DAT_00855de0 == 2 || (DAT_00855de0 == 3)))) || (DAT_0093b2a8 != 0)) ||
       (((((DAT_00951154 != 0 || ((*(uint *)(*(int *)(iVar3 + 0x128) + 100) & 0x200) != 0)) ||
          ((*(int *)(iVar3 + 300) != 0 && ((*(ushort *)(*(int *)(iVar3 + 300) + 0x7a) & 0x124) != 0)
           ))) || ((iVar4 = FUN_00574e20(), iVar4 != -1 || (_DAT_00950780 != 0.0)))) ||
        ((*(int *)(iVar3 + 300) != 0 &&
         (((*(int *)(iVar3 + 300) == DAT_00951364 && (DAT_0095de4c != (code *)0x0)) &&
          (iVar3 = (*DAT_0095de4c)(), iVar3 != 0)))))))) {
      bVar2 = false;
    }
    if ((DAT_00856c08 != 0) || (iVar3 = FUN_0058a900(0), iVar3 != 0)) {
      bVar2 = false;
    }
    sVar1 = *DAT_009514b4;
    psVar5 = DAT_009514b4;
    while (sVar1 != -1) {
      if ((DAT_009514b8 != psVar5) && (0.0 < *(float *)(psVar5 + 0xc))) {
        *(float *)(psVar5 + 0xc) = *(float *)(psVar5 + 0xc) - param_1;
      }
      if ((((bVar2) && (DAT_009514b8 == (short *)0x0)) && ((char)psVar5[10] == '\0')) &&
         (((*(code **)(psVar5 + 8) != (code *)0x0 &&
           (iVar3 = (**(code **)(psVar5 + 8))(psVar5), iVar3 != 0)) &&
          ((*(float *)(psVar5 + 0xc) <= 0.0 && ((char)psVar5[10] != '\x01')))))) {
        FUN_00576860(psVar5,0,0);
      }
      psVar5 = psVar5 + 0xe;
      sVar1 = *psVar5;
    }
    if (DAT_009514d0 == (code *)0x0) {
      fVar6 = (float10)1;
    }
    else {
      fVar6 = (float10)(*DAT_009514d0)();
    }
    fVar6 = (float10)FUN_0054fad0(_DAT_009514cc,(float)fVar6,_DAT_00925018 * 3.0);
    _DAT_009514cc = (float)fVar6;
    if (((DAT_009514b8 != (short *)0x0) &&
        (_DAT_009514c8 = _DAT_009514c8 + param_1, 0.0 < *(float *)(DAT_009514b8 + 4))) &&
       (*(float *)(DAT_009514b8 + 4) < _DAT_009514c8 !=
        (*(float *)(DAT_009514b8 + 4) == _DAT_009514c8))) {
      DAT_009514b8 = (short *)0x0;
    }
  }
  return;
}

