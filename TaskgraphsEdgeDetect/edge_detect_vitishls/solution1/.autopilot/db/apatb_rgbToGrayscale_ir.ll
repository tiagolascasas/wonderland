; ModuleID = 'C:/Users/Tiago/Dev/ClavaExperiments/TaskgraphsEdgeDetect/edge_detect_vitishls/solution1/.autopilot/db/a.g.ld.5.gdce.bc'
source_filename = "llvm-link"
target datalayout = "e-m:e-i64:64-i128:128-i256:256-i512:512-i1024:1024-i2048:2048-i4096:4096-n8:16:32:64-S128-v16:16-v24:32-v32:32-v48:64-v96:128-v192:256-v256:256-v512:512-v1024:1024"
target triple = "fpga64-xilinx-none"

; Function Attrs: noinline
define void @apatb_rgbToGrayscale_ir([1536 x i32]* noalias nocapture nonnull readonly "fpga.decayed.dim.hint"="512" %input_image, [512 x i32]* noalias nocapture nonnull "fpga.decayed.dim.hint"="512" %output_image) local_unnamed_addr #0 {
entry:
  %malloccall = tail call i8* @malloc(i64 3145728)
  %input_image_copy = bitcast i8* %malloccall to [512 x [1536 x i32]]*
  %malloccall1 = tail call i8* @malloc(i64 1048576)
  %output_image_copy = bitcast i8* %malloccall1 to [512 x [512 x i32]]*
  %0 = bitcast [1536 x i32]* %input_image to [512 x [1536 x i32]]*
  %1 = bitcast [512 x i32]* %output_image to [512 x [512 x i32]]*
  call fastcc void @copy_in([512 x [1536 x i32]]* nonnull %0, [512 x [1536 x i32]]* %input_image_copy, [512 x [512 x i32]]* nonnull %1, [512 x [512 x i32]]* %output_image_copy)
  %2 = getelementptr inbounds [512 x [1536 x i32]], [512 x [1536 x i32]]* %input_image_copy, i32 0, i32 0
  %3 = getelementptr inbounds [512 x [512 x i32]], [512 x [512 x i32]]* %output_image_copy, i32 0, i32 0
  call void @apatb_rgbToGrayscale_hw([1536 x i32]* %2, [512 x i32]* %3)
  call void @copy_back([512 x [1536 x i32]]* %0, [512 x [1536 x i32]]* %input_image_copy, [512 x [512 x i32]]* %1, [512 x [512 x i32]]* %output_image_copy)
  tail call void @free(i8* %malloccall)
  tail call void @free(i8* %malloccall1)
  ret void
}

declare noalias i8* @malloc(i64) local_unnamed_addr

; Function Attrs: argmemonly noinline norecurse
define internal fastcc void @copy_in([512 x [1536 x i32]]* noalias readonly, [512 x [1536 x i32]]* noalias, [512 x [512 x i32]]* noalias readonly, [512 x [512 x i32]]* noalias) unnamed_addr #1 {
entry:
  call fastcc void @onebyonecpy_hls.p0a512a1536i32([512 x [1536 x i32]]* %1, [512 x [1536 x i32]]* %0)
  call fastcc void @onebyonecpy_hls.p0a512a512i32([512 x [512 x i32]]* %3, [512 x [512 x i32]]* %2)
  ret void
}

; Function Attrs: argmemonly noinline norecurse
define internal fastcc void @onebyonecpy_hls.p0a512a1536i32([512 x [1536 x i32]]* noalias, [512 x [1536 x i32]]* noalias readonly) unnamed_addr #2 {
entry:
  %2 = icmp eq [512 x [1536 x i32]]* %0, null
  %3 = icmp eq [512 x [1536 x i32]]* %1, null
  %4 = or i1 %2, %3
  br i1 %4, label %ret, label %copy

copy:                                             ; preds = %entry
  br label %for.loop

for.loop:                                         ; preds = %for.loop.split, %copy
  %for.loop.idx10 = phi i64 [ 0, %copy ], [ %for.loop.idx.next, %for.loop.split ]
  br label %for.loop2

for.loop2:                                        ; preds = %for.loop2, %for.loop
  %for.loop.idx39 = phi i64 [ 0, %for.loop ], [ %for.loop.idx3.next, %for.loop2 ]
  %dst.addr57 = getelementptr [512 x [1536 x i32]], [512 x [1536 x i32]]* %0, i64 0, i64 %for.loop.idx10, i64 %for.loop.idx39
  %src.addr68 = getelementptr [512 x [1536 x i32]], [512 x [1536 x i32]]* %1, i64 0, i64 %for.loop.idx10, i64 %for.loop.idx39
  %5 = load i32, i32* %src.addr68, align 4
  store i32 %5, i32* %dst.addr57, align 4
  %for.loop.idx3.next = add nuw nsw i64 %for.loop.idx39, 1
  %exitcond = icmp ne i64 %for.loop.idx3.next, 1536
  br i1 %exitcond, label %for.loop2, label %for.loop.split

for.loop.split:                                   ; preds = %for.loop2
  %for.loop.idx.next = add nuw nsw i64 %for.loop.idx10, 1
  %exitcond11 = icmp ne i64 %for.loop.idx.next, 512
  br i1 %exitcond11, label %for.loop, label %ret

ret:                                              ; preds = %for.loop.split, %entry
  ret void
}

; Function Attrs: argmemonly noinline norecurse
define internal fastcc void @onebyonecpy_hls.p0a512a512i32([512 x [512 x i32]]* noalias, [512 x [512 x i32]]* noalias readonly) unnamed_addr #2 {
entry:
  %2 = icmp eq [512 x [512 x i32]]* %0, null
  %3 = icmp eq [512 x [512 x i32]]* %1, null
  %4 = or i1 %2, %3
  br i1 %4, label %ret, label %copy

copy:                                             ; preds = %entry
  br label %for.loop

for.loop:                                         ; preds = %for.loop.split, %copy
  %for.loop.idx10 = phi i64 [ 0, %copy ], [ %for.loop.idx.next, %for.loop.split ]
  br label %for.loop2

for.loop2:                                        ; preds = %for.loop2, %for.loop
  %for.loop.idx39 = phi i64 [ 0, %for.loop ], [ %for.loop.idx3.next, %for.loop2 ]
  %dst.addr57 = getelementptr [512 x [512 x i32]], [512 x [512 x i32]]* %0, i64 0, i64 %for.loop.idx10, i64 %for.loop.idx39
  %src.addr68 = getelementptr [512 x [512 x i32]], [512 x [512 x i32]]* %1, i64 0, i64 %for.loop.idx10, i64 %for.loop.idx39
  %5 = load i32, i32* %src.addr68, align 4
  store i32 %5, i32* %dst.addr57, align 4
  %for.loop.idx3.next = add nuw nsw i64 %for.loop.idx39, 1
  %exitcond = icmp ne i64 %for.loop.idx3.next, 512
  br i1 %exitcond, label %for.loop2, label %for.loop.split

for.loop.split:                                   ; preds = %for.loop2
  %for.loop.idx.next = add nuw nsw i64 %for.loop.idx10, 1
  %exitcond11 = icmp ne i64 %for.loop.idx.next, 512
  br i1 %exitcond11, label %for.loop, label %ret

ret:                                              ; preds = %for.loop.split, %entry
  ret void
}

; Function Attrs: argmemonly noinline norecurse
define internal fastcc void @copy_out([512 x [1536 x i32]]* noalias, [512 x [1536 x i32]]* noalias readonly, [512 x [512 x i32]]* noalias, [512 x [512 x i32]]* noalias readonly) unnamed_addr #3 {
entry:
  call fastcc void @onebyonecpy_hls.p0a512a1536i32([512 x [1536 x i32]]* %0, [512 x [1536 x i32]]* %1)
  call fastcc void @onebyonecpy_hls.p0a512a512i32([512 x [512 x i32]]* %2, [512 x [512 x i32]]* %3)
  ret void
}

declare void @free(i8*) local_unnamed_addr

declare void @apatb_rgbToGrayscale_hw([1536 x i32]*, [512 x i32]*)

; Function Attrs: argmemonly noinline norecurse
define internal fastcc void @copy_back([512 x [1536 x i32]]* noalias, [512 x [1536 x i32]]* noalias readonly, [512 x [512 x i32]]* noalias, [512 x [512 x i32]]* noalias readonly) unnamed_addr #3 {
entry:
  call fastcc void @onebyonecpy_hls.p0a512a512i32([512 x [512 x i32]]* %2, [512 x [512 x i32]]* %3)
  ret void
}

define void @rgbToGrayscale_hw_stub_wrapper([1536 x i32]*, [512 x i32]*) #4 {
entry:
  %2 = bitcast [1536 x i32]* %0 to [512 x [1536 x i32]]*
  %3 = bitcast [512 x i32]* %1 to [512 x [512 x i32]]*
  call void @copy_out([512 x [1536 x i32]]* null, [512 x [1536 x i32]]* %2, [512 x [512 x i32]]* null, [512 x [512 x i32]]* %3)
  %4 = bitcast [512 x [1536 x i32]]* %2 to [1536 x i32]*
  %5 = bitcast [512 x [512 x i32]]* %3 to [512 x i32]*
  call void @rgbToGrayscale_hw_stub([1536 x i32]* %4, [512 x i32]* %5)
  call void @copy_in([512 x [1536 x i32]]* null, [512 x [1536 x i32]]* %2, [512 x [512 x i32]]* null, [512 x [512 x i32]]* %3)
  ret void
}

declare void @rgbToGrayscale_hw_stub([1536 x i32]*, [512 x i32]*)

attributes #0 = { noinline "fpga.wrapper.func"="wrapper" }
attributes #1 = { argmemonly noinline norecurse "fpga.wrapper.func"="copyin" }
attributes #2 = { argmemonly noinline norecurse "fpga.wrapper.func"="onebyonecpy_hls" }
attributes #3 = { argmemonly noinline norecurse "fpga.wrapper.func"="copyout" }
attributes #4 = { "fpga.wrapper.func"="stub" }

!llvm.dbg.cu = !{}
!llvm.ident = !{!0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0}
!llvm.module.flags = !{!1, !2, !3}
!blackbox_cfg = !{!4}

!0 = !{!"clang version 7.0.0 "}
!1 = !{i32 2, !"Dwarf Version", i32 4}
!2 = !{i32 2, !"Debug Info Version", i32 3}
!3 = !{i32 1, !"wchar_size", i32 4}
!4 = !{}
