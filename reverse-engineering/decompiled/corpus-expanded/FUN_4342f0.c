/* Ghidra pseudocode, not original source.
 * ev_a581b26cc49c1240ca9fc8201471236b1c0a2571dfff42173a4e3442f2e0fd27
 * Entry: 0x4342f0; label: FUN_004342f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004342f0(short *param_1)

{
  short sVar1;
  char *pcVar2;
  uint *puVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  bool bVar8;
  
  if ((*(int *)(PTR_DAT_00802c54 + 300) != 0) && (*(int *)(PTR_DAT_00802c54 + 300) == DAT_00951364))
  {
    return 0;
  }
  piVar4 = &DAT_0093d7f4;
  uVar6 = DAT_00876d9c;
  do {
    iVar5 = piVar4[-1];
    if ((((iVar5 != 0) && ((*(uint *)(iVar5 + 0x1fc) & 0x1000) != 0)) &&
        ((char)*(uint *)(iVar5 + 0x1fc) < '\0')) && (*(short *)(iVar5 + 0x1064) == DAT_007f1a58)) {
      uVar6 = uVar6 | 2;
      DAT_00876d9c = uVar6;
    }
    iVar5 = *piVar4;
    if (((iVar5 != 0) && ((*(uint *)(iVar5 + 0x1fc) & 0x1000) != 0)) &&
       (((char)*(uint *)(iVar5 + 0x1fc) < '\0' && (*(short *)(iVar5 + 0x1064) == DAT_007f1a58)))) {
      uVar6 = uVar6 | 2;
      DAT_00876d9c = uVar6;
    }
    iVar5 = piVar4[1];
    if (((iVar5 != 0) && ((*(uint *)(iVar5 + 0x1fc) & 0x1000) != 0)) &&
       (((char)*(uint *)(iVar5 + 0x1fc) < '\0' && (*(short *)(iVar5 + 0x1064) == DAT_007f1a58)))) {
      uVar6 = uVar6 | 2;
      DAT_00876d9c = uVar6;
    }
    iVar5 = piVar4[2];
    if ((((iVar5 != 0) && ((*(uint *)(iVar5 + 0x1fc) & 0x1000) != 0)) &&
        ((char)*(uint *)(iVar5 + 0x1fc) < '\0')) && (*(short *)(iVar5 + 0x1064) == DAT_007f1a58)) {
      uVar6 = uVar6 | 2;
      DAT_00876d9c = uVar6;
    }
    piVar4 = piVar4 + 4;
  } while ((int)piVar4 < 0x93d814);
  sVar1 = *param_1;
  switch(sVar1) {
  case 600:
    if (DAT_0093b2a4 == 0) {
      return 0;
    }
    if (((DAT_0093d810 != 0) && ((*(byte *)(DAT_0093d810 + 0x1fc) & 0x80) != 0)) &&
       (*(int *)(DAT_0093d810 + 0xcd0) != 0)) {
      return 0;
    }
    if (DAT_0093d814 == 0) {
      return 1;
    }
    if ((*(byte *)(DAT_0093d814 + 0x1fc) & 0x80) == 0) {
      return 1;
    }
    goto LAB_0043462c;
  case 0x25a:
    if ((uVar6 & 1) == 0) {
      return 0;
    }
    if (DAT_0087a7c4 != 0) {
LAB_00434414:
      FUN_005769b0(param_1);
      return 0;
    }
    if (DAT_00951288 != 0) {
      return 0;
    }
    if (*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_00951b94) {
      return 0;
    }
    if (((DAT_0093d810 != 0) && ((*(byte *)(DAT_0093d810 + 0x1fc) & 0x80) != 0)) &&
       (*(int *)(DAT_0093d810 + 0xcd0) != 0)) {
      return 0;
    }
    if (((DAT_0093d814 != 0) && ((*(byte *)(DAT_0093d814 + 0x1fc) & 0x80) != 0)) &&
       (*(int *)(DAT_0093d814 + 0xcd0) != 0)) {
      return 0;
    }
    iVar7 = 0;
    iVar5 = 0;
    piVar4 = &DAT_0093d7f4;
    do {
      if (piVar4[-1] != 0) {
        uVar6 = *(uint *)(piVar4[-1] + 0x1fc);
        iVar5 = iVar5 + 1;
        if (((uVar6 & 0x1000) != 0) && ((char)uVar6 < '\0')) {
          iVar7 = iVar7 + 1;
        }
      }
      if (*piVar4 != 0) {
        uVar6 = *(uint *)(*piVar4 + 0x1fc);
        iVar5 = iVar5 + 1;
        if (((uVar6 & 0x1000) != 0) && ((char)uVar6 < '\0')) {
          iVar7 = iVar7 + 1;
        }
      }
      if (piVar4[1] != 0) {
        uVar6 = *(uint *)(piVar4[1] + 0x1fc);
        iVar5 = iVar5 + 1;
        if (((uVar6 & 0x1000) != 0) && ((char)uVar6 < '\0')) {
          iVar7 = iVar7 + 1;
        }
      }
      if (piVar4[2] != 0) {
        uVar6 = *(uint *)(piVar4[2] + 0x1fc);
        iVar5 = iVar5 + 1;
        if (((uVar6 & 0x1000) != 0) && ((char)uVar6 < '\0')) {
          iVar7 = iVar7 + 1;
        }
      }
      piVar4 = piVar4 + 4;
    } while ((int)piVar4 < 0x93d814);
    if ((iVar5 == 2) && (iVar7 == 2)) {
      return 0;
    }
    if ((DAT_0093d810 != 0) && (*(int *)(DAT_0093d810 + 0xcd0) == 0)) {
      return 1;
    }
    if (DAT_0093d814 == 0) {
      return 0;
    }
    iVar5 = *(int *)(DAT_0093d814 + 0xcd0);
    goto LAB_00434633;
  case 0x25b:
    if ((uVar6 & 4) == 0) {
      if (DAT_0087a7c4 < 2) {
        return 0;
      }
      DAT_0087a7c4 = 1;
      return 0;
    }
    iVar5 = FUN_00576480(0x25a);
    if (DAT_0087a7c4 == 2) goto LAB_00434414;
    if (DAT_0087a7c4 != 1) {
      return 0;
    }
    if ((iVar5 != 0) && (iVar5 = FUN_00576540(iVar5), iVar5 == 0)) {
      return 0;
    }
    if (DAT_00951288 != 0) {
      return 0;
    }
    if (*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_00951b94) {
      return 0;
    }
    if ((DAT_0093d810 != 0) && (*(int *)(DAT_0093d810 + 0xcd0) == 0)) {
      return 1;
    }
    if (DAT_0093d814 == 0) {
      return 0;
    }
LAB_0043462c:
    iVar5 = *(int *)(DAT_0093d814 + 0xcd0);
LAB_00434633:
    if (iVar5 == 0) {
      return 1;
    }
    break;
  case 0x25d:
  case 0x263:
  case 0x28a:
    iVar5 = 0;
    if (0 < DAT_0093d500) {
      puVar3 = (uint *)(DAT_0093d504 + 0x1fc);
      do {
        if (((((*puVar3 & 1) != 0) && ((*puVar3 & 0x1000) != 0)) &&
            (*(char *)((int)puVar3 + 0x8f) == '\0')) && ((puVar3[0x309] & 0x80000000) != 0)) {
          if (((short)puVar3[0x39a] == DAT_007f1974) || ((short)puVar3[0x39a] == DAT_007f1978)) {
            bVar8 = sVar1 == 0x28a;
          }
          else if (*(code **)(puVar3[-0x6a] + 0x18) == FUN_004b3000) {
            bVar8 = sVar1 == 0x263;
          }
          else {
            bVar8 = sVar1 == 0x25d;
          }
          if (bVar8) {
            return 1;
          }
        }
        iVar5 = iVar5 + 1;
        puVar3 = puVar3 + 0x436;
        if (DAT_0093d500 <= iVar5) {
          return 0;
        }
      } while( true );
    }
    break;
  case 0x25e:
    if ((((((DAT_0093d7f0 != 0) && ((*(byte *)(DAT_0093d7f0 + 0x1fc) & 0x80) != 0)) &&
          (*(int *)(DAT_0093d7f0 + 0xcd0) != 0)) &&
         (*(short *)(DAT_0093d7f0 + 0x1064) != DAT_007f198c)) ||
        (((DAT_0093d7f4 != 0 && ((*(byte *)(DAT_0093d7f4 + 0x1fc) & 0x80) != 0)) &&
         ((*(int *)(DAT_0093d7f4 + 0xcd0) != 0 &&
          (*(short *)(DAT_0093d7f4 + 0x1064) != DAT_007f198c)))))) &&
       ((*(int *)(PTR_DAT_00802c54 + 0x128) != DAT_0087b234 || (DAT_009253a4 != 0)))) {
      return 1;
    }
    break;
  case 0x287:
    if ((*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b234) &&
       (((DAT_0093d7f0 != 0 && (*(short *)(DAT_0093d7f0 + 0x1064) == DAT_007f1948)) ||
        ((DAT_0093d7f4 != 0 && (*(short *)(DAT_0093d7f4 + 0x1064) == DAT_007f1948)))))) {
      return 1;
    }
    break;
  case 0x289:
    if (DAT_00951288 != 0) {
      if ((((DAT_0093d7f0 != 0) &&
           (pcVar2 = *(char **)(DAT_0093d7f0 + 0xcc4), pcVar2 != (char *)0x0)) && (*pcVar2 != '\0'))
         && (*(int *)(pcVar2 + 0x84) != 0)) {
        return 1;
      }
      if (((DAT_0093d7f4 != 0) && (pcVar2 = *(char **)(DAT_0093d7f4 + 0xcc4), pcVar2 != (char *)0x0)
          ) && ((*pcVar2 != '\0' && (*(int *)(pcVar2 + 0x84) != 0)))) {
        return 1;
      }
    }
    break;
  case 0x28b:
    if ((((DAT_0093d7f0 != 0) && ((*(byte *)(DAT_0093d7f0 + 0x1fc) & 0x80) != 0)) &&
        ((*(short *)(DAT_0093d7f0 + 0x1064) == DAT_007f1974 ||
         (*(short *)(DAT_0093d7f0 + 0x1064) == DAT_007f1978)))) ||
       (((DAT_0093d7f4 != 0 && ((*(byte *)(DAT_0093d7f4 + 0x1fc) & 0x80) != 0)) &&
        ((*(short *)(DAT_0093d7f4 + 0x1064) == DAT_007f1974 ||
         (*(short *)(DAT_0093d7f4 + 0x1064) == DAT_007f1978)))))) {
      return 1;
    }
    break;
  case 0x28e:
    if (DAT_00951288 != 0) {
      bVar8 = false;
      piVar4 = &DAT_0093d7f0;
      while ((int)piVar4 < 0x93d7f8) {
        iVar5 = *piVar4;
        if (((iVar5 != 0) && ((*(byte *)(iVar5 + 0x1fc) & 0x80) != 0)) &&
           ((*(char *)(iVar5 + 0x28b) == '\0' && ((*(byte *)(iVar5 + 0xe24) & 0x10) != 0)))) {
          bVar8 = true;
        }
        piVar4 = piVar4 + 1;
        if (bVar8) {
          return 1;
        }
      }
      if (bVar8) {
        return 1;
      }
    }
  }
  return 0;
}

