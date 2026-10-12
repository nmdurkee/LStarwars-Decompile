/* Ghidra pseudocode, not original source.
 * ev_e036c7439cd20116919e592c8e070cde3540a7375a0b02133844a56e359aaeed
 * Entry: 0x4a1c70; label: FUN_004a1c70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004a1c70(int param_1,int param_2)

{
  char cVar1;
  float fVar2;
  int in_EAX;
  float *pfVar3;
  int iVar4;
  float10 fVar5;
  float local_c [2];
  float local_4;
  
  cVar1 = *(char *)(in_EAX + 0x7b5);
  if (cVar1 == '\x10') {
    pfVar3 = (float *)FUN_0062f150(in_EAX + 8,(int)*(short *)(in_EAX + 0x7aa),1,0);
    if (pfVar3 != (float *)0x0) {
      if ((*(byte *)(in_EAX + 0x7bc) & 0x40) == 0) {
        fVar5 = (float10)FUN_0062f1f0(*(undefined4 *)(in_EAX + 0x50),(int)*(short *)(in_EAX + 0x7aa)
                                      ,0);
        if ((1.0 <= (float)fVar5) && ((float)fVar5 <= *pfVar3)) {
          FUN_0058e360();
        }
      }
      fVar2 = *(float *)(in_EAX + 0x77c) - _DAT_00925018;
      *(float *)(in_EAX + 0x77c) = fVar2;
      if (fVar2 <= 0.0) {
        *(uint *)(in_EAX + 0xe20) = *(uint *)(in_EAX + 0xe20) | 4;
        *(undefined1 *)(in_EAX + 0x7b5) = 0xff;
        if (*(short *)(in_EAX + 0x7aa) == 0x29) {
          if ((*(byte *)(in_EAX + 0x7bc) & 0x40) == 0) {
            FUN_0058e360();
            *(undefined4 *)(in_EAX + 0x77c) = 0x3a83126f;
            *(undefined1 *)(in_EAX + 0x7b5) = 0x10;
          }
          else if (param_2 != 0) {
            FUN_0058e3b0();
            return;
          }
        }
      }
    }
    return;
  }
  if ((((((*(byte *)(in_EAX + 0xe22) & 1) != 0) && (*(char *)(in_EAX + 0xe33) == '\0')) &&
       (param_1 != 0)) && ((*(char *)(in_EAX + 0x281) != '\0' && (*(int *)(in_EAX + 0x50) != 0))))
     && ((((cVar1 == -1 || ((cVar1 == '\x01' || (cVar1 == '\x02')))) ||
          ((cVar1 == '\x04' || (cVar1 == '\x03')))) &&
         (iVar4 = FUN_0049d200(0x3f19999a,0,2), iVar4 == 1)))) {
    if (*(int *)(in_EAX + 0x790) == 0) {
      if (*(int *)(in_EAX + 0x794) == 0) {
        return;
      }
      iVar4 = *(int *)(in_EAX + 0x794) + 0x4c;
    }
    else {
      iVar4 = *(int *)(in_EAX + 0x790) + 0x5c;
    }
    if (iVar4 != 0) {
      FUN_005b3800(local_c,iVar4,in_EAX + 0x5c);
      FUN_005b3620(local_c,local_c,-(uint)*(ushort *)(in_EAX + 0x5a));
      if ((((*(float *)(*(int *)(in_EAX + 0xca4) + 0x28) <= 0.0) ||
           (ABS(local_c[0]) <= ABS(local_4))) && (local_4 < 0.0)) &&
         ((_DAT_0087b89c < 0.48999998 &&
          (*(undefined2 *)(in_EAX + 0x7aa) = 0x29,
          *(int *)(*(int *)(*(int *)(in_EAX + 0x50) + 0xc) + 0xa4) != 0)))) {
        fVar5 = (float10)FUN_0062e040((int)*(short *)(in_EAX + 0x1064),0x29,0,0,1);
        *(float *)(in_EAX + 0x77c) = (float)fVar5;
        if (0.0 < (float)fVar5) {
          *(uint *)(in_EAX + 0x7bc) = *(uint *)(in_EAX + 0x7bc) & 0xffffffbf;
          *(undefined1 *)(in_EAX + 0x7b5) = 0x10;
          FUN_00548540(0);
          FUN_0054a850(**(undefined4 **)(in_EAX + 0xca4),0x3ecccccd,0);
          return;
        }
      }
    }
  }
  return;
}

