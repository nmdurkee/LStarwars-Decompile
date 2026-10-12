/* Ghidra pseudocode, not original source.
 * ev_e8754f098cec4467dd9989e7d0bc7b4ce6834c9196706effdc433d5dfb6256ff
 * Entry: 0x405ac0; label: FUN_00405ac0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00405ac0(void)

{
  float fVar1;
  byte bVar2;
  int iVar3;
  char cVar4;
  int *piVar5;
  float10 fVar6;
  int local_1c;
  
  piVar5 = &DAT_0085491c;
  local_1c = 8;
  do {
    if (*(char *)((int)piVar5 + -7) != '\0') {
      fVar1 = (float)piVar5[-1] + _DAT_00925018;
      piVar5[-1] = (int)fVar1;
      if ((2.0 <= fVar1) && (4.0 < fVar1)) {
        piVar5[-1] = 0x40800000;
      }
      if (*(char *)((int)piVar5 + (uint)*(byte *)((int)piVar5 + -6) * 0x14 + -0x7f) != '\0') {
        do {
          if (*(byte *)(piVar5 + -2) <= *(byte *)((int)piVar5 + -6)) break;
          bVar2 = *(byte *)((int)piVar5 + -6) + 1;
          *(byte *)((int)piVar5 + -6) = bVar2;
        } while (*(char *)((int)piVar5 + (uint)bVar2 * 0x14 + -0x7f) != '\0');
      }
      iVar3 = FUN_004058a0(piVar5 + -0x21);
      if (iVar3 != 0) {
        bVar2 = *(byte *)((int)piVar5 + -6);
        if (bVar2 < *(byte *)(piVar5 + -2)) {
          cVar4 = (char)piVar5[(uint)bVar2 * 5 + -0x20];
          iVar3 = (piVar5 + -0x21)[(uint)bVar2 * 5];
          if (cVar4 != '\x03') {
            FUN_0054a850(**(undefined4 **)(*piVar5 + 0xca4),0x3f000000,0);
            FUN_0054a8d0(**(undefined4 **)(*piVar5 + 0xca4),1,0);
            FUN_00549f10();
          }
          *(char *)((int)piVar5 + -6) = *(char *)((int)piVar5 + -6) + '\x01';
          piVar5[-1] = 0;
          if (cVar4 == '\0') {
            if ((*(short *)(iVar3 + 0x1064) == DAT_007f17c0) && (*(char *)(iVar3 + 0x280) == -1)) {
              *(uint *)(iVar3 + 0xeec) = *(uint *)(iVar3 + 0xeec) | 1;
              FUN_00432330(iVar3,*piVar5,_DAT_007ef224,0);
            }
            else if ((*(uint *)(iVar3 + 0xeec) & 0x8000000) == 0) {
              FUN_00438230(*piVar5,iVar3,1,0,0,1);
            }
          }
          else if (cVar4 == '\x01') {
            FUN_00426f60(iVar3);
          }
          else if (cVar4 == '\x02') {
            FUN_00567800(iVar3,1,2,2,0,1);
          }
        }
        else {
          *(undefined4 *)(*piVar5 + 0xde4) = 0;
          FUN_0054a8d0(**(undefined4 **)(*piVar5 + 0xca4),1,0);
          iVar3 = *piVar5;
          if ((*(uint *)(*(int *)(iVar3 + 0xca4) + 4) & DAT_0080227c) == 0) {
            if (((*(float *)(*(int *)(iVar3 + 0xca4) + 0x28) == 0.0) &&
                (*(char *)(iVar3 + 0x7b5) == -1)) &&
               (*(int *)(*(int *)(*(int *)(iVar3 + 0x50) + 0xc) + 0x260) != 0)) {
              *(undefined1 *)(iVar3 + 0x7b5) = 0x50;
              *(undefined2 *)(*piVar5 + 0x7aa) = 0x98;
              fVar6 = (float10)FUN_0062e040((int)*(short *)(*piVar5 + 0x1064),
                                            (int)*(short *)(*piVar5 + 0x7aa),0,0,1);
              *(float *)(*piVar5 + 0x77c) = (float)fVar6;
            }
          }
          else {
            FUN_00404fa0(iVar3);
          }
          *(undefined1 *)((int)piVar5 + -7) = 0;
          *(undefined1 *)(piVar5 + -2) = 0;
          *piVar5 = 0;
          *(undefined2 *)(piVar5 + 10) = 0x32;
        }
      }
    }
    piVar5 = piVar5 + 0x2d;
    local_1c = local_1c + -1;
    if (local_1c == 0) {
      return;
    }
  } while( true );
}

